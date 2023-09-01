/*
 * Motor.c
 *
 *  Created on: Aug 31, 2023
 *      Author: EUI-Support
 */


//Spin motor in one direction by giving IN1 and IN2 signals to L298N
#include"STD_TYPE.h"
#include "TM4C123GH6PM.h"
#include"Motor.h"


void Turn_oneDirection(void)
{
     SYSCTL_RCGCGPIO_R |= 0x01;   /* enable clock to PORTF */
     GPIO_PORTA_DIR_R  |= 0xFF ;          /* pin digital */
     GPIO_PORTA_DEN_R  |= 0xFF  ;       /* pin digital */
     GPIO_PORTA_DATA_R |=(1<<2);
     GPIO_PORTA_DATA_R &=~(1<<3);
     GPIO_PORTA_DATA_R |=(1<<4);
     GPIO_PORTA_DATA_R &=~(1<<5);

}


void Turn_OtherDirection(void)
{
    SYSCTL_RCGCGPIO_R |= 0x01;   /* enable clock to PORTF */
    GPIO_PORTA_DIR_R |= (1<<3)|(1<<2);            /* pin digital */
    GPIO_PORTA_DEN_R |= (1<<3)|(1<<2);
    GPIO_PORTA_DATA_R |=(1<<3);/* pin digital */
    GPIO_PORTA_DATA_R &=~(1<<2);
}

void PWM_init(void)
{


//    GPIO_PORTF_AFSEL_R |= 0x04;         /* Data sheet page 671 */
//    GPIO_PORTF_PCTL_R |= (0x07<<8);     /* Data sheet page 688 */
//
//
//    CLR_BIT(TIMER1_CTL_R,0); // Enable PWM
//    TIMER1_CFG_R=0x4;
//
//    TIMER1_TAMR_R|=0x2;
//    SET_BIT(TIMER1_TAMR_R,3);
//    CLR_BIT(TIMER1_TAMR_R,2);
//
//    CLR_BIT(TIMER1_CTL_R,6);
//
//    TIMER1_TAILR_R=0X3E80;
//
//    SET_BIT(TIMER1_CTL_R,0);
}



void Delay_ms(int time_ms)
{
    int i, j;
    for(i = 0 ; i < time_ms; i++)
        for(j = 0; j < 3180; j++)
            {}  /* excute NOP for 1ms */
}

void Duty_Cycle (f32 pwm)
{
    TIMER1_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
    TIMER3_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
}




void PWM_Freq_KHZ(u16 freq)
{
    if (freq==0);
    else
    {
        u16 Ttotal=1000/freq;
        if (Ttotal>=1)
        {
            TIMER1_TAMATCHR_R=Ttotal-1;
        }
        else TIMER1_TAMATCHR_R=0;

    }
}
