

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
/* ADC from TivaWare */

/**** HAL *****/
/* UltraSonic */
/* Motors */
/* LDRs with TivaWare */
/* On board Temperature Sensor with TivaWare */
/* LCD */


 /*defines*/
#define LED_RED     (PF1)  /* PF3/LEDR */
#define LED_BLU     (PF2)  /* PF1/LEDB */
#define LED_GRN     (PF3)  /* PF2/LEDG */


 /*global variables*/
volatile uint8_t start_flag = 1;

void LCD_Display(uint32_t temp, uint32_t ultra, uint32_t left, uint32_t right);
void carStop(void);


/**
 * main.c
 */
void main(void)
{
    /* Initialization */

    DIO_PORT_Init(PORTA);
    DIO_PORT_Init(PORTB);

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
	            /* turn 180 */
	            /* motors fun here */
	            turn_Car(LEFT, 180);
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
                /* Stop the car otherwise */
                carStop();
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

void carStop(void)
{
	DIO_WritePin(MOTOR1_CTL_1, LOW);
        DIO_WritePin(MOTOR1_CTL_2, LOW);
        DIO_WritePin(MOTOR2_CTL_1, LOW);
        DIO_WritePin(MOTOR2_CTL_2, LOW);
}
