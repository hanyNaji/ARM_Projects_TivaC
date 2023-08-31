
#include "Tiva_DIO/Tiva_DIO.h"
#include "Tiva_GPTimers/Tiva_GPTimers.h"
#include "ultraSonic/ultraSonic.h"
#include "LCD_Driver/LCD_Driver.h"



#define LED_RED     (PF1)  /* PF3/LEDR */
#define LED_BLU     (PF2)  /* PF1/LEDB */
#define LED_GRN     (PF3)  /* PF2/LEDG */

#define SW1         (PF4)  /* PF4/SW1 */
#define SW2         (PF0)  /* PF0/SW2 */


#define TRIG_PIN     (PC5)  /* for signal out pin */
#define ECHO_PIN     (PC4)  /* for capture pin */

/* Timer frequency for the system clock */
#define SEC_FREQ    (16000000UL)



volatile uint32_t read_old;
volatile uint32_t read_new;
volatile uint8_t distance;

/* GPIO PORTF Interrupt handler */
void GPIOF_Handler(void)
{
    if (GPIO_PORTF_MIS_R & (1UL << (SW1 % 8UL)))  Check if interrupt is caused by PF4/SW1
    {
        /*read_new = GPTcapture_read(GPTM_EdgeTimer.timer);
        GPIO_PORTF_ICR_R |= (1UL << (SW1 % 8UL));*/
    }
    else {
         Do nothing for MISRA
    }
}



/**
 * main.c
 */
void main(void);
void main(void)
{
    /* Initialize ports and pins */
    DIO_PORT_Init(PORTF);
    DIO_PORT_Init(PORTB);
    DIO_PORT_Init(PORTA);
    DIO_PORT_Init(PORTC);
/*

    DIO_InitPin(LED_RED, OUTPUT);
    DIO_InitPin(LED_BLU, OUTPUT);
    DIO_InitPin(LED_GRN, OUTPUT);

    DIO_InitPin(SW1, INLLUP);
    Interrupt_Edge_InitPin(SW1, LOW_EDGE);

    DIO_InitPin(SW2, OUTPUT);
    DIO_WritePin(SW2, HIGH);
*/

    ultraSonic_Init(TRIG_PIN, ECHO_PIN);

    /* Initialize LCD and all its connected pins*/
    LCD_Init();

    /* just printing HELLO*/
    LCD_SetCursor(0, 3);
    LCD_WriteString("HELLO...");

    while(812)
    {
        _delay_ms(500);
        distance = ultraSonic_ReadCM();
        if(distance != read_old){
            read_old = distance;
            LCD_Clear();
            LCD_WriteNumber(distance);
        }
    }
}






