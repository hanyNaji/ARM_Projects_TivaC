
#include "Tiva_DIO/Tiva_DIO.h"
#include "LCD_Driver/LCD_Driver.h"



#define LED_RED     1  /* PF3/LEDR */
#define LED_BLU     2  /* PF1/LEDB */
#define LED_GRN     3  /* PF2/LEDG */

#define SW1         4  /* PF4/SW1 */
#define SW2         0  /* PF0/SW2 */


volatile unsigned char systick_flag ;  /* flag to detect Systick underflow */
volatile unsigned char moments ;  /* to calculate moments of the stop watch */
volatile unsigned char seconds ;  /* to calculate seconds of the stop watch */
volatile unsigned char minutes ;  /* to calculate minutes of the stop watch */
volatile unsigned char hours ;  /* to calculate hours of the stop watch */
volatile unsigned char GPIOF_flag ;  /* flag to detect GPIO PORTF Interrupt */


void writeHours(void);
void writeMinutes(void);
void writeSeconds(void);
void writeMoments(void);


/* Systick Interrupt handler */
void IntSystickHandler(void)
{
    if(moments==9U) {
        moments = 0U;
        if(seconds==59U){
            seconds = 0U;
            if(minutes==59U){
                minutes=0U;
                if(hours==23U){
                    hours=0U;
                }
                else {
                    hours++;
                    systick_flag =4U;
                }
            }
            else {
                minutes++;
                systick_flag =3U;
            }
        }
        else {
            seconds++;
            systick_flag =2U;
        }
    }
    else {
        moments++;
        systick_flag =1U;
    }
}


/* GPIO PORTF Interrupt handler */
void GPIOF_Handler(void)
{
    if (GPIO_PORTF_MIS_R & (unsigned long)(1U<<SW1)) /* check if interrupt causes by PF4/SW1*/
    {
        GPIOF_flag = 1U;
        GPIO_PORTF_ICR_R |= (unsigned long)(1U<<SW1);
    }
    else if (GPIO_PORTF_MIS_R & (unsigned long)(1U<<SW2)) /* check if interrupt causes by PF0/SW2 */
    {
        GPIOF_flag = 2;
        GPIO_PORTF_ICR_R |= (unsigned long)(1U<<SW2);
    }
    else {
        /* for misra */
    }
}

/**
 * main.c
 */
void main(void)
{
    DIO_PORT_Init(PORTF);
    DIO_PORT_Init(PORTA);
    DIO_PORT_Init(PORTB);
    DIO_PORT_Init(PORTE);
    DIO_InitPin(PORTF, LED_RED, OUTPUT);
    DIO_InitPin(PORTF, LED_BLU, OUTPUT);
    DIO_InitPin(PORTF, SW1, INLLUP);
    DIO_InitPin(PORTF, SW2, INLLUP);
    Inteupt_Edge_InitPin(PORTF, SW1, LOW_EDGE);
    Inteupt_Edge_InitPin(PORTF, SW2, LOW_EDGE);

    LCD_Init();
    LCD_SetCursor(0U, 0U);
    LCD_WriteString(" SW1: START");
    LCD_SetCursor(1U, 0U);
    LCD_WriteString(" SW2: STOP");

    Systick_Reload_ms((unsigned long long)100);

    volatile unsigned char intend =0U ;
    while(812)
    {
        /* Disable the systick if switch 2 pressed and stop the STOP WATCH */
        if(2U == GPIOF_flag)
        {
            GPIOF_flag = 0U;
            Systick_Disable();
            DIO_WritePin(PORTF, LED_BLU, LOW);
            DIO_WritePin(PORTF, LED_RED, HIGH);

            LCD_SetCursor(1U, 0U);
            writeHours();
            LCD_WriteChar(':');
            writeMinutes();
            LCD_WriteChar(':');
            writeSeconds();
            LCD_WriteChar('.');
            writeMoments();
            LCD_SetCursor(0U, 11U);
            LCD_WriteString("PAUSE");
        }

        /* Enable the systick if switch 1 pressed and start the STOP WATCH */
        else if(1U == GPIOF_flag)
        {
            GPIOF_flag = 0U;
            DIO_WritePin(PORTF, LED_RED, LOW);

            Systick_Init(ST_INTENABLE);

            if(!intend){
                LCD_Clear();
                intend =1U;
            }else{
                LCD_SetCursor(0U, 11U);
                LCD_WriteString("     ");
            }
            LCD_SetCursor(0U, 0U);
            writeHours();
            LCD_WriteChar(':');
            writeMinutes();
            LCD_WriteChar(':');
            writeSeconds();
            LCD_WriteChar('.');
            writeMoments();


        }
        else{

        }

        if(systick_flag)
        {
            if(4U == systick_flag){
                LCD_SetCursor(0U, 0U);
                writeHours();
            }
            else{
            }

            if(3U == systick_flag){
                LCD_SetCursor(0U, 3U);
                writeMinutes();
            }
            else{
            }

            if(2U == systick_flag){
                LCD_SetCursor(0U, 6U);
                writeSeconds();
                DIO_TogglePin(PORTF, LED_BLU);
            }
            else{
            }

            if(1U == systick_flag){
                LCD_SetCursor(0U, 9U);
                writeMoments();
            }
            else{
            }

            systick_flag = 0U;
        }
        else{
        }

    }
}


void writeHours(void)
{
    if(hours<10U)
    {
        LCD_WriteNumber(0);
        LCD_WriteNumber((long long)hours);
    }
    else
    {
        LCD_WriteNumber((long long)hours);
    }
}

void writeMinutes(void)
{
    if(minutes<10U)
    {
        LCD_WriteNumber(0);
        LCD_WriteNumber((long long)minutes);
    }
    else
    {
        LCD_WriteNumber((long long)minutes);
    }
}

void writeSeconds(void)
{
    if(seconds<10U)
    {
        LCD_WriteNumber(0);
        LCD_WriteNumber((long long)seconds);
    }
    else
    {
        LCD_WriteNumber((long long)seconds);
    }
}


void writeMoments(void)
{
    if(moments<10U)
    {
        LCD_WriteNumber((long long)moments);
    }
    else{
    }
}


