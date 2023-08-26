/*
 * Tiva_GPTimers.c
 *
 *  Created on: Aug 25, 2023
 *      Author: hany nagy
 */


#include "Tiva_GPTimers.h"


void enable(void){
    GPT_Enable();
}

void disable(void){

}


void Init(void)
{
    GPT_Init(GPTM_EdgeTimer.timer, GPTM_EdgeTimer.mode, GPTM_EdgeTimer.preScale);
}

void start(void)
{
    INSERT_BIT(WTIMER0_CTL_R, 0, 1);

}

void stop(void)
{
    INSERT_BIT(WTIMER0_CTL_R, 0, 0);
}


uint32_t read(void)
{
    return (WTIMER0_TAR_R);
}


void GPT_Enable(void)
{

    TIMER0_CFG_R &= ~(0x07);

}

void GPT_Mode(GPT_ModeType mode)
{
    switch(mode){
        case ONE_SHOT:
            break;
        case PERIODIC:
            break;
        case CAPTURE:
            INSERT_BIT(WTIMER0_CTL_R, 0, 0);
            INSERT_BIT(WTIMER0_CFG_R, 2, 1);
            INSERT_BIT(WTIMER0_TAMR_R, 2, GPTM_EdgeTimer.captureMode);
            INSERT_BITS(WTIMER0_TAMR_R, GPTM_EdgeTimer.mode, 0, 2);
            INSERT_BIT(WTIMER0_TAMR_R, 4, GPTM_EdgeTimer.dirMode);
            INSERT_BITS(WTIMER0_CTL_R, GPTM_EdgeTimer.eventMode, 2, 2);

            break;
        default:
            break;
    }
}


void GPT_Init(GPT_Type timer, GPT_ModeType mode, uint8_t preScale)
{
    switch(timer){
        case TIMER0:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 0, 1);
            TIMER0_CFG_R &= ~(0x07);
//            TIMER0_TAMR_R
            break;
        case TIMER1:
            break;
        case TIMER2:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 2, 1);
            GPT_Mode(GPTM_EdgeTimer.mode);
            TIMER2_TAPR_R = preScale;

//            TIMER0_TAMR_R
            break;
        case TIMER3:
            break;
        case TIMER4:
            break;
        case TIMER5:
            break;
        case TIMER_W0:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 0, 1);
            GPT_Mode(GPTM_EdgeTimer.mode);
            WTIMER0_TAPR_R = preScale;
            break;
        case TIMER_W1:
            break;
        case TIMER_W2:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 2, 1);
            GPT_Mode(GPTM_EdgeTimer.mode);
//            WTIMER2_TAPR_R = preScale;
            break;
        case TIMER_W3:
            break;
        case TIMER_W4:
            break;
        case TIMER_W5:
            break;
        default:
            break;
    }
}

void GPT_CCP_PinInit(DIO_AllPINS_TYPE pin)
{
    uint8_t Port = pin / 8;
    uint8_t pin_num = pin % 8;
    switch (Port)
    {
        case PORTA:
            INSERT_BITS(GPIO_PORTA_PCTL_R, 0x07, 16, 4);
            break;
        case PORTB:
            INSERT_BITS(GPIO_PORTB_PCTL_R, 0x07, 16, 4);
            break;
        case PORTC:
            INSERT_BITS(GPIO_PORTC_PCTL_R, 0x07, 16, 4);
            break;
        case PORTD:
            INSERT_BITS(GPIO_PORTD_PCTL_R, 0x07, 16, 4);
            break;
        case PORTE:
            INSERT_BITS(GPIO_PORTE_PCTL_R, 0x07, 16, 4);
            break;
        case PORTF:
            INSERT_BITS(GPIO_PORTF_PCTL_R, 0x07, 16, 4);
            break;
    }
}
