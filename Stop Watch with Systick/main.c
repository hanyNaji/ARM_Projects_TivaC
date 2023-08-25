
#include "Tiva_DIO/Tiva_DIO.h"
#include "LCD_Driver/LCD_Driver.h"



#define LED_RED     (PF1)  /* PF3/LEDR */
#define LED_BLU     (PF2)  /* PF1/LEDB */
#define LED_GRN     (PF3)  /* PF2/LEDG */

#define SW1         (PF4)  /* PF4/SW1 */
#define SW2         (PF0)  /* PF0/SW2 */


volatile uint8_t  systick_flag ;   /* flag to detect Systick underflow */
volatile uint8_t  moments ;        /* to calculate moments of the stop watch */
volatile uint8_t  seconds ;        /* to calculate seconds of the stop watch */
volatile uint8_t  minutes ;        /* to calculate minutes of the stop watch */
volatile uint8_t  hours ;          /* to calculate hours of the stop watch */
volatile uint8_t  GPIOF_flag ;     /* flag to detect GPIO PORTF Interrupt */


/**
 * @brief Writes the hours portion to the LCD in the format HH.
 */
void writeHours(void);

/**
 * @brief Writes the minutes portion to the LCD in the format MM.
 */
void writeMinutes(void);

/**
 * @brief Writes the seconds portion to the LCD in the format SS.
 */
void writeSeconds(void);

/**
 * @brief Writes the moments portion to the LCD in the format m.
 */
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
    if (GPIO_PORTF_MIS_R & (uint32_t)(1U<<(SW1%8))) /* check if interrupt causes by PF4/SW1*/
    {
        GPIOF_flag = 1U;
        GPIO_PORTF_ICR_R |= (unsigned long)(1U<<(SW1%8));
    }
    else if (GPIO_PORTF_MIS_R & (unsigned long)(1U<<(SW2%8))) /* check if interrupt causes by PF0/SW2 */
    {
        GPIOF_flag = 2;
        GPIO_PORTF_ICR_R |= (unsigned long)(1U<<(SW2%8));
    }
    else {
        /* Do nothing for MISRA */
    }
}

/**
 * main.c
 */
void main(void);
void main(void)
{
    DIO_PORT_Init(PORTF);
    DIO_PORT_Init(PORTA);
    DIO_PORT_Init(PORTB);
    DIO_PORT_Init(PORTE);
    DIO_InitPin(LED_RED, OUTPUT);
    DIO_InitPin(LED_BLU, OUTPUT);
    DIO_InitPin(SW1, INLLUP);
    DIO_InitPin(SW2, INLLUP);
    Inteupt_Edge_InitPin(SW1, LOW_EDGE);
    Inteupt_Edge_InitPin(SW2, LOW_EDGE);

    LCD_Init();
    LCD_SetCursor(0U, 0U);
    LCD_WriteString(" SW1: START");
    LCD_SetCursor(1U, 0U);
    LCD_WriteString(" SW2: PAUSE");

    Systick_Reload_ms(100U);

    volatile uint8_t intend = 0U ;
    while(812)
    {
        /* Disable the systick if switch 2 pressed and stop the STOP WATCH */
        if(2U == GPIOF_flag)
        {
            GPIOF_flag = 0U;
            Systick_Disable();
            DIO_WritePin(LED_BLU, LOW);
            DIO_WritePin(LED_RED, HIGH);

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
            DIO_WritePin(LED_RED, LOW);

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
        else {
                /* Do nothing for MISRA */
            }

        if(systick_flag)
        {
            if(4U == systick_flag){
                LCD_SetCursor(0U, 0U);
                writeHours();
            }
            else {
                    /* Do nothing for MISRA */
                }

            if(3U == systick_flag){
                LCD_SetCursor(0U, 3U);
                writeMinutes();
            }
            else {
                    /* Do nothing for MISRA */
                }

            if(2U == systick_flag){
                LCD_SetCursor(0U, 6U);
                writeSeconds();
                DIO_TogglePin(LED_BLU);
            }
            else {
                    /* Do nothing for MISRA */
                }

            if(1U == systick_flag){
                LCD_SetCursor(0U, 9U);
                writeMoments();
            }
            else {
                    /* Do nothing for MISRA */
                }

            systick_flag = 0U;
        }
        else {
                /* Do nothing for MISRA */
            }

    }
}



/**
 * @brief Writes the hours portion to the LCD in the format HH.
 */
void writeHours(void)
{
    if (hours < 10U)
    {
        LCD_WriteNumber(0);
        LCD_WriteNumber((int32_t)hours);
    }
    else
    {
        LCD_WriteNumber((int32_t)hours);
    }
}

/**
 * @brief Writes the minutes portion to the LCD in the format MM.
 */
void writeMinutes(void)
{
    if (minutes < 10U)
    {
        LCD_WriteNumber(0);
        LCD_WriteNumber((int32_t)minutes);
    }
    else
    {
        LCD_WriteNumber((int32_t)minutes);
    }
}

/**
 * @brief Writes the seconds portion to the LCD in the format SS.
 */
void writeSeconds(void)
{
    if (seconds < 10U)
    {
        LCD_WriteNumber(0);
        LCD_WriteNumber((int32_t)seconds);
    }
    else
    {
        LCD_WriteNumber((int32_t)seconds);
    }
}

/**
 * @brief Writes the moments portion to the LCD in the format M.
 *        Only executed when moments are less than 10.
 *        For moments >= 10, nothing is displayed (MISRA compliance).
 */
void writeMoments(void)
{
    if (moments < 10U)
    {
        LCD_WriteNumber((int32_t)moments);
    }
    else {
        /* Do nothing for MISRA */
    }
}
