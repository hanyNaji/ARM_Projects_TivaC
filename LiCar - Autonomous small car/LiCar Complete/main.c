
/*TivaWare includes*/
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/lcd.h"

/* Private includes*/
#include "Tiva_DIO/Tiva_DIO.h"
#include "DC_motor/DC_motor.h"
#include "Tiva_GPTimers/Tiva_GPTimers.h"
#include "ultraSonic/ultraSonic.h"
#include "LCD_Driver/LCD_Driver.h"
#include "Sensors/Sensor.h"


/****  MCAL  ****/
/* DIO*/
/* Timers*/
/* ADC TivaWare */

/**** HAL *****/
// Hany
/* UltraSonic */

// Waleed & Hamdy & Hany
/* Motors */

// Shaf3y
/* LDRs TivaWare */

// Amr
/* Temperature Sensor TivaWare */

// ALL
/* LCD */


 /*defines*/
#define LED_RED     (PF1)  /* PF3/LEDR */
#define LED_BLU     (PF2)  /* PF1/LEDB */
#define LED_GRN     (PF3)  /* PF2/LEDG */

#define SW1         (PF4)  /* PF4/SW1 */
#define SW2         (PF0)  /* PF0/SW2 */


 /*global variables*/
volatile uint8_t start_flag = 1;


/* Interrupts */
/* start if SW1 pressed */
/* stop if SW2 pressed */

/* GPIO PORTF Interrupt handler */
void GPIOF_Handler(void)
{
    if (GPIO_PORTF_MIS_R & (1UL << (SW1 % 8UL)))  /*Check if interrupt is caused by PF4/SW1*/
    {
        start_flag = 1;
        GPIO_PORTF_ICR_R |= (1UL << (SW1 % 8UL));

    }
    else if (GPIO_PORTF_MIS_R & (1UL << (SW2 % 8UL)))  /*Check if interrupt is caused by PF0/SW2*/
    {
        start_flag = 0;
        DIO_WritePin(MOTOR1_CTL_1, LOW);
        DIO_WritePin(MOTOR1_CTL_2, LOW);
        DIO_WritePin(MOTOR2_CTL_1, LOW);
        DIO_WritePin(MOTOR2_CTL_2, LOW);
        GPIO_PORTF_ICR_R |= (1UL << (SW2 % 8UL));

    }
    else {
         /*Do nothing for MISRA*/
    }
}

void LCD_Display(uint32_t temp, uint32_t ultra, uint32_t left, uint32_t right);

/**
 * main.c
 */
void main(void)
{
    /* Initialization */

    DIO_PORT_Init(PORTA);
    DIO_PORT_Init(PORTB);

//    DIO_InitPin(SW1, INLLUP);
//    Interrupt_Edge_InitPin(SW1, LOW_EDGE);
//
//    DIO_InitPin(SW2, INLLUP);
//    Interrupt_Edge_InitPin(SW2, LOW_EDGE);

    /* UltraSonic */
    ultraSonic_Init(TRIG_PIN, ECHO_PIN);

    /* Motors */
    PWM_init(TIMER1);
    PWM_init(TIMER3);

    PWM_PinInit(MOTOR1_PWM);
    PWM_PinInit(MOTOR2_PWM);

    Duty_Cycle (TIMER1, 50);
    Duty_Cycle (TIMER3, 50);

    DIO_InitPin(MOTOR1_CTL_1, OUTPUT);
    DIO_InitPin(MOTOR1_CTL_2, OUTPUT);
    DIO_InitPin(MOTOR2_CTL_1, OUTPUT);
    DIO_InitPin(MOTOR2_CTL_2, OUTPUT);

//    turn_Car(LEFT, 90);
//    move_Forward(SPEED);


    /* LDRs */
    LDR_Left();     /* PE2 */
    LDR_Right();    /* PE3 */

    /* Temperature Sensor */
    temp_Init();    /* PE1 */

    /* LCD */
    /* Initialize LCD and all its connected pins*/
    LCD_Init();


    /**************************/
    volatile uint32_t distance=0;
    volatile uint32_t temp=0;
    volatile uint32_t left=0;
    volatile uint32_t right=0;


	while(812)
	{
	    temp=Temp_Read();
        READ_LEFT(&left);
        READ_Right(&right);
	    distance = ultraSonic_ReadCM();

        LCD_Display(temp, distance, left, right);

	    if(start_flag)
	    {
	        distance = ultraSonic_ReadCM();
	        if(distance < 10){
	            /* return 180 */
	            /* motors fun here */
	            turn_Car(LEFT, 180);
//	            move_Forward(SPEED);
	        }


	        READ_LEFT(&left);
	        READ_Right(&right);
	        int32_t ldrDiff = left - right;

            if(ldrDiff > 100 ){
                /* turn Right */
                /* motors fun here */
                turn_Car(RIGHT, ANGLE);
                move_Forward(SPEED);
            }
            else if(ldrDiff < -150 ){
                /* turn Left */
                /* motors fun here */
                turn_Car(LEFT, ANGLE);
                move_Forward(SPEED);
            }
            else
            {

                DIO_WritePin(MOTOR1_CTL_1, LOW);
                DIO_WritePin(MOTOR1_CTL_2, LOW);
                DIO_WritePin(MOTOR2_CTL_1, LOW);
                DIO_WritePin(MOTOR2_CTL_2, LOW);

            }
	    }
	    else
	    {
	        /* */
	    }
	}
}


void LCD_Display(uint32_t temp, uint32_t ultra, uint32_t left, uint32_t right)
{
//    static uint32_t t=0, u=0, l=0, r=0;
//    if(t!= temp){
//
//    }

    LCD_SetCursor(0, 0);
    LCD_WriteString("T= ");
    LCD_WriteNumber_2D(temp-36);
    LCD_WriteString(" | US= ");
    LCD_WriteNumber_3D(ultra);
    LCD_SetCursor(1, 0);
    LCD_WriteString("LL:");
    LCD_WriteNumber_4D(left);
    LCD_WriteString(" LR:");
    LCD_WriteNumber_4D(right);
}
