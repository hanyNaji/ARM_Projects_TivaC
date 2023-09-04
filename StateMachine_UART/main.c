
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "inc/hw_ints.h"
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/systick.h"
#include "utils/uartstdio.h"


#define RED_LED    GPIO_PIN_1
#define BLUE_LED   GPIO_PIN_2
#define GREEN_LED  GPIO_PIN_3

#define INT_SW1    GPIO_PIN_4

#define MAX_LEN    200

enum{
    UARTOFF=0,
    UART_RO,
    UART_RW,
    UART_ER
}volatile STATE;

char data[202];
uint8_t ind;


char dataRec[202];
uint8_t indRec;


void serialDebug(uint32_t baudRate);
void LED_IND(uint8_t state);

/*****************************************************************************

 Delay for the specified number of seconds.  Depending upon the current
 SysTick value, the delay will be between N-1 and N seconds (i.e. N-1 full
 seconds are guaranteed, aint32_t with the remainder of the current second).

*****************************************************************************/
void
Delay(uint32_t ui32Seconds)
{
    /* Loop while there are more seconds to wait.*/
    while(ui32Seconds--)
    {
        /* Wait until the SysTick value is less than 1000.*/
        while(MAP_SysTickValueGet() > 1000)
        {
        }

        /* Wait until the SysTick value is greater than 1000.*/
        while(MAP_SysTickValueGet() < 1000)
        {
        }
    }
}

void
UARTSend(uint32_t ui32UARTBase, const uint8_t *pui8Buffer, uint32_t ui32Count)
{
    while(ui32Count--)
    {

        /* Write the next character to the UART.*/
        UARTCharPut(ui32UARTBase, *pui8Buffer++);
    }
}

/*****************************************************************************
 This is the handler for INT_GPIOF.  It increments the state
*****************************************************************************/
void
IntGPIOf(void)
{
    GPIOIntClear(GPIO_PORTF_BASE, INT_SW1);
    /* Increment the current state.*/
    if(STATE < 2)
    {
        STATE ++;
    }
    else
    {
        STATE = UARTOFF;
    }
}


void main(void)
{

    char cThisChar;
    char cThisCharRec;
    uint8_t stateFlag[3]={0};

    /* Set the clocking to run directly from the external crystal/oscillator.
       crystal on your board.*/
    SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
                   SYSCTL_XTAL_16MHZ);


    /* Set up and enable the SysTick timer.  It will be used as a reference
    // for delay loops in the interrupt handlers.  The SysTick timer period
    // will be set up for one second.
     */
    MAP_SysTickPeriodSet(MAP_SysCtlClockGet());
    MAP_SysTickEnable();

    /*
     The UART itself needs to be enabled, as well as the GPIO port
     containing the pins that will be used.
     */
    serialDebug(115200);
    Delay(1);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART5);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);

    GPIOPinConfigure(GPIO_PE4_U5RX);
    GPIOPinConfigure(GPIO_PE5_U5TX);

    GPIOPinTypeUART(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);

    UARTConfigSetExpClk(UART5_BASE, SysCtlClockGet(), 9600,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                         UART_CONFIG_PAR_NONE));


    UARTSend(UART0_BASE, (uint8_t *)"\n[1]: Hello",
             strlen("\n[1]: Hello"));

    /* Enable the GPIO port that is used for the on-board LED. */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);

    /* Check if the peripheral access is enabled. */
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    }

    /* Enable the GPIO pin for the LED (PF3).  Set the direction as output, and
     enable the GPIO pin for digital function. */

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED_LED);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, BLUE_LED);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GREEN_LED);

    /* Enable the interrupts.*/
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, INT_SW1);
    GPIOPadConfigSet(GPIO_PORTF_BASE, INT_SW1, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOIntTypeSet(GPIO_PORTF_BASE, INT_SW1, GPIO_FALLING_EDGE);
    GPIOIntEnable(GPIO_PORTF_BASE, INT_SW1);

    IntEnable(INT_GPIOF);

    while(812)
    {
        switch(STATE)
        {
            case UARTOFF:  /* Off-Line state ignore every thing */
                UARTSend(UART0_BASE, (uint8_t *)"\r\nOff-Line! ", strlen("\r\nOff-Line! "));
                UARTDisable(UART0_BASE);
                UARTDisable(UART5_BASE);
                stateFlag[1] = 0;
                stateFlag[2] = 0;
                LED_IND(UARTOFF);
                ind = 0;
                indRec = 0;
                while(STATE == UARTOFF);
                break;

            case UART_RO:   /* Read-Only state Read msg and show it on PC */
                UARTEnable(UART0_BASE);
                UARTEnable(UART5_BASE);
                LED_IND(UART_RO);
                ind = 0;
                indRec = 0;
                if(!stateFlag[1]){
                    UARTSend(UART0_BASE, (uint8_t *)"\r\nRead-Only: ", strlen("\r\nRead-Only: "));
                    stateFlag[1] = 1;
                    stateFlag[2] = 0;
                }
                UARTSend(UART0_BASE, (uint8_t *)"\r\n[2]: ", strlen("\r\n[2]: "));
                UARTDisable(UART0_BASE);
                do
                {

                    /* Read a character using the non blocking read function.  */
                    cThisChar = UARTCharGetNonBlocking(UART5_BASE);
                    if((int8_t)cThisChar != -1){
                        if(ind < MAX_LEN){
                            data[ind++] = cThisChar;
                            if((cThisChar == '#'))
                            {
                                UARTEnable(UART0_BASE);
                                UARTSend(UART0_BASE, (uint8_t*)data, ind);
                                UARTSend(UART0_BASE, (uint8_t *)"\r[2]: ", strlen("\r[2]: "));
                                UARTDisable(UART0_BASE);
                                ind=0;
                            }
                        }
                        else if(ind >= MAX_LEN){
                            STATE = UART_ER;
                            ind=0;
                        }else {
                        }
                    }
                }
                while((cThisChar != '#') && (STATE == UART_RO));
                break;

            case UART_RW:   /* Read-Write state Read/write msg and show it on PC */
                UARTEnable(UART0_BASE);
                UARTEnable(UART5_BASE);
                LED_IND(UART_RW);
                ind = 0;
                indRec = 0;
                if(!stateFlag[2]){
                    UARTSend(UART0_BASE, (uint8_t *)"\r\nRead-Write: ", strlen("\r\nRead-Write: "));
                    stateFlag[1] = 0;
                    stateFlag[2] = 1;
                }
                UARTSend(UART0_BASE, (uint8_t *)"\r\n[1]: ", strlen("\r\n[1]: "));
                do
                {
                    /* Read a character using the non blocking read function.  */
                    cThisCharRec = UARTCharGetNonBlocking(UART5_BASE);
                    if(cThisCharRec != 255){
                        if(indRec < MAX_LEN){
                            dataRec[indRec++] = cThisCharRec;
                            if((cThisCharRec == '#'))
                            {
                                UARTSend(UART0_BASE, (uint8_t*)dataRec, indRec);
                                indRec=0;
                                UARTSend(UART0_BASE, (uint8_t *)"\r[2]: ", strlen("\r[2]: "));
                            }
                        }
                        else if(indRec >= MAX_LEN){
                            STATE = UART_ER;
                            indRec=0;
                        }else {
                        }
                    }
                    /* Read a character using the non blocking read function.  */
                    cThisChar = UARTCharGetNonBlocking(UART0_BASE);
                    if(cThisChar != 255){
                        if(ind < MAX_LEN){
                            data[ind++] = cThisChar;
                            /* Write the same character on terminal */
                            UARTCharPut(UART0_BASE, cThisChar);
                            if((cThisChar == '\n') || (cThisChar == '\r'))
                            {
                                UARTSend(UART5_BASE, (uint8_t*)data, ind);
                                UARTCharPut(UART5_BASE, '#');
                                ind=0;
                            }
                        }
                        else if(ind >= MAX_LEN){
                            STATE = UART_ER;
                            ind =0;
                        }else {
                        }
                    }

                }
                while((cThisCharRec != '#') && (cThisChar != '\n') && (cThisChar != '\r')&&(STATE == UART_RW));
                break;

            case UART_ER:
                UARTDisable(UART0_BASE);
                UARTDisable(UART5_BASE);
                stateFlag[1] = 0;
                stateFlag[2] = 0;
                LED_IND(UART_ER);
                break;

            default:
                break;
        }

    }

}


/*
 The UART itself needs to be enabled, as well as the GPIO port
 containing the pins that will be used.
 */
void serialDebug(uint32_t baudRate)
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), baudRate,
                        (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |
                         UART_CONFIG_PAR_NONE));

}


void LED_IND(uint8_t state)
{
    switch(state)
    {
        case UARTOFF:
            /* Turn off the LED Red. */
            GPIOPinWrite(GPIO_PORTF_BASE, RED_LED, RED_LED);
            GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x0);
            GPIOPinWrite(GPIO_PORTF_BASE, BLUE_LED, 0x0);
            break;

        case UART_RO:
            /* Turn on the LED Blue. */
            GPIOPinWrite(GPIO_PORTF_BASE, RED_LED, 0x0);
            GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x0);
            GPIOPinWrite(GPIO_PORTF_BASE, BLUE_LED, BLUE_LED);
            break;

        case UART_RW:
            /* Turn off the LED Green. */
            GPIOPinWrite(GPIO_PORTF_BASE, RED_LED, RED_LED);
            GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, GREEN_LED);
            GPIOPinWrite(GPIO_PORTF_BASE, BLUE_LED, BLUE_LED);
            break;

        case UART_ER:
            /* Turn off the LED Red. */
            GPIOPinWrite(GPIO_PORTF_BASE, RED_LED, RED_LED);
            GPIOPinWrite(GPIO_PORTF_BASE, GREEN_LED, 0x0);
            GPIOPinWrite(GPIO_PORTF_BASE, BLUE_LED, 0x0);
            break;

        default:
            break;
    }
}


