/*
 * Tiva_GPTimers.c
 *
 *  Created on: Aug 25, 2023
 *      Author: hany nagy
 */


#include "Tiva_GPTimers.h"




uint32_t GPTcapture_read(GPT_Type timer_N)
{
    uint32_t read = 0UL;
    switch(timer_N){
            case TIMER0:
                read = (uint32_t)TIMER0_TAR_R;
                break;
            case TIMER1:
                read = (uint32_t)TIMER1_TAR_R;
                break;
            case TIMER2:
                read = (uint32_t)TIMER2_TAR_R;
                break;
            case TIMER3:
                read = (uint32_t)TIMER3_TAR_R;
                break;
            case TIMER4:
                read = (uint32_t)TIMER4_TAR_R;
                break;
            case TIMER5:
                read = (uint32_t)TIMER5_TAR_R;
                break;
            case TIMER_W0:
                read = (uint32_t)WTIMER0_TAR_R;
                break;
            case TIMER_W1:
                read = (uint32_t)WTIMER1_TAR_R;
                break;
            case TIMER_W2:
                read = (uint32_t)WTIMER2_TAR_R;
                break;
            case TIMER_W3:
                read = (uint32_t)WTIMER3_TAR_R;
                break;
            case TIMER_W4:
                read = (uint32_t)WTIMER4_TAR_R;
                break;
            case TIMER_W5:
                read = (uint32_t)WTIMER5_TAR_R;
                break;
            default:
                break;
        }
    return read;
}


void GPT_Enable(GPT_Type timer_N)
{
    switch(timer_N){
            case TIMER0:
                INSERT_BIT(TIMER0_CTL_R, 0UL, 1UL);
                break;
            case TIMER1:
                INSERT_BIT(TIMER1_CTL_R, 0UL, 1UL);
                break;
            case TIMER2:
                INSERT_BIT(TIMER2_CTL_R, 0UL, 1UL);
                break;
            case TIMER3:
                INSERT_BIT(TIMER3_CTL_R, 0UL, 1UL);
                break;
            case TIMER4:
                INSERT_BIT(TIMER4_CTL_R, 0UL, 1UL);
                break;
            case TIMER5:
                INSERT_BIT(TIMER5_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W0:
                INSERT_BIT(WTIMER0_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W1:
                INSERT_BIT(WTIMER1_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W2:
                INSERT_BIT(WTIMER2_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W3:
                INSERT_BIT(WTIMER3_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W4:
                INSERT_BIT(WTIMER4_CTL_R, 0UL, 1UL);
                break;
            case TIMER_W5:
                INSERT_BIT(WTIMER5_CTL_R, 0UL, 1UL);
                break;
            default:
                break;
        }

}


void GPT_Disable(GPT_Type timer_N)
{
    switch(timer_N){
        case TIMER0:
            INSERT_BIT(TIMER0_CTL_R, 0UL, 0UL);
            break;
        case TIMER1:
            INSERT_BIT(TIMER1_CTL_R, 0UL, 0UL);
            break;
        case TIMER2:
            INSERT_BIT(TIMER2_CTL_R, 0UL, 0UL);
            break;
        case TIMER3:
            INSERT_BIT(TIMER3_CTL_R, 0UL, 0UL);
            break;
        case TIMER4:
            INSERT_BIT(TIMER4_CTL_R, 0UL, 0UL);
            break;
        case TIMER5:
            INSERT_BIT(TIMER5_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W0:
            INSERT_BIT(WTIMER0_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W1:
            INSERT_BIT(WTIMER1_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W2:
            INSERT_BIT(WTIMER2_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W3:
            INSERT_BIT(WTIMER3_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W4:
            INSERT_BIT(WTIMER4_CTL_R, 0UL, 0UL);
            break;
        case TIMER_W5:
            INSERT_BIT(WTIMER5_CTL_R, 0UL, 0UL);
            break;
        default:
            break;
    }

}


void GPT_Init(GPT_Struct *st_timer)
{
    switch(st_timer->timer){
        case TIMER0:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 0UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER0_CTL_R, 0UL, 0UL);
                    INSERT_BIT(TIMER0_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER0_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER0_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER0_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER0_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER0_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER1:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 1UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER1_CTL_R, 0UL, 0UL);
                    INSERT_BIT(TIMER1_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER1_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER1_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER1_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER1_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER1_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER2:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 2UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER2_CTL_R, 0UL, 0UL);
                    INSERT_BIT(TIMER2_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER2_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER2_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER2_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER2_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER2_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER3:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 3UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER3_CTL_R, 0UL, 0UL);
                    INSERT_BIT(TIMER3_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER3_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER3_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER3_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER3_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER3_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER4:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 4UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER4_CTL_R, 0UL, 0UL);
                    INSERT_BIT(TIMER4_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER4_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER4_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER4_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER4_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER4_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER5:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 5UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(TIMER5_CTL_R, 0UL, 0UL);
                    INSERT_BIT(TIMER5_CFG_R, 2UL, 1UL);
                    INSERT_BIT(TIMER5_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(TIMER5_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(TIMER5_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(TIMER5_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            TIMER5_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W0:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 0UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER0_CTL_R, 0UL, 0UL);
                    INSERT_BIT(WTIMER0_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER0_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER0_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER0_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER0_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    INSERT_BIT(WTIMER0_IMR_R, 2UL, st_timer->intType);
                    break;
                default:
                    break;
            }
            WTIMER0_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W1:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 1UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER1_CTL_R, 0UL, 0UL);
                    INSERT_BIT(WTIMER1_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER1_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER1_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER1_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER1_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            WTIMER1_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W2:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 2UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER2_CTL_R, 0UL, 0UL);
                    INSERT_BIT(WTIMER2_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER2_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER2_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER2_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER2_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            WTIMER2_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W3:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 3UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER3_CTL_R, 0UL, 0UL);
                    INSERT_BIT(WTIMER3_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER3_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER3_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER3_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER3_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            WTIMER3_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W4:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 4UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER4_CTL_R, 0UL, 0UL);
                    INSERT_BIT(WTIMER4_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER4_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER4_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER4_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER4_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            WTIMER4_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        case TIMER_W5:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 5UL, 1UL);
            switch(st_timer->mode){
                case ONE_SHOT:
                    break;
                case PERIODIC:
                    break;
                case CAPTURE:
                    INSERT_BIT(WTIMER5_CTL_R, 0UL, 0UL);
                    INSERT_BIT(WTIMER5_CFG_R, 2UL, 1UL);
                    INSERT_BIT(WTIMER5_TAMR_R, 2UL, st_timer->captureMode);
                    INSERT_BITS(WTIMER5_TAMR_R, st_timer->mode, 0UL, 2UL);
                    INSERT_BIT(WTIMER5_TAMR_R, 4UL, st_timer->dirMode);
                    INSERT_BITS(WTIMER5_CTL_R, st_timer->eventMode, 2UL, 2UL);
                    break;
                default:
                    break;
            }
            WTIMER5_TAPR_R = (uint32_t)st_timer->preScale;
            break;
        default:
            break;
    }
}

void GPT_CCP_PinInit(DIO_AllPINS_TYPE pin)
{
    uint8_t Port_N = (uint8_t) pin / 8;
    switch (Port_N)
    {
        case PORTA:
            INSERT_BITS(GPIO_PORTA_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        case PORTB:
            INSERT_BITS(GPIO_PORTB_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        case PORTC:
            INSERT_BITS(GPIO_PORTC_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        case PORTD:
            INSERT_BITS(GPIO_PORTD_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        case PORTE:
            INSERT_BITS(GPIO_PORTE_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        case PORTF:
            INSERT_BITS(GPIO_PORTF_PCTL_R, 0x07UL, 16UL, 4UL);
            break;
        default:
            break;
    }
}



/*
 * This function captures consecutive rising and falling edges
 * of a periodic signal from Timer
 * and returns the time difference (the period of the signal).
 */
uint32_t TimerACapture_PulseWidth(GPT_Type timer_N, DIO_AllPINS_TYPE ccp_pin)
{
    uint32_t risingEdge=0, fallingEdge=0;
    switch (timer_N)
    {
        case TIMER0:
            while(1)
            {
                INSERT_BIT(TIMER0_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER0_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER0_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER0_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER0_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER0_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER1:
            while(1)
            {
                INSERT_BIT(TIMER1_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER1_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER1_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER1_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER1_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER1_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER2:
            while(1)
            {
                INSERT_BIT(TIMER2_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER2_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER2_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER2_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER2_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER2_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER3:
            while(1)
            {
                INSERT_BIT(TIMER3_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER3_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER3_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER3_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER3_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER3_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER4:
            while(1)
            {
                INSERT_BIT(TIMER4_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER4_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER4_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER4_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER4_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER4_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER5:
            while(1)
            {
                INSERT_BIT(TIMER5_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                while((READ_BIT(TIMER5_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = TIMER5_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(TIMER5_ICR_R, 2UL, 1UL);             /* clear timer0A capture flag */
                    while((TIMER5_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = TIMER5_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER_W0:
            while(1)
            {
                INSERT_BIT(WTIMER0_ICR_R, 2UL, 1UL);                /* clear WTIMER0A capture flag */
                while(! DIO_ReadPin(ccp_pin));               /* wait till captured */
                risingEdge = WTIMER0_TAR_R;     /* save the timestamp */
                /* detect falling edge */
                INSERT_BIT(WTIMER0_ICR_R, 2UL, 1UL);                /* clear WTIMER0A capture flag */
                while(DIO_ReadPin(ccp_pin));                 /* wait till captured */
                fallingEdge = WTIMER0_TAR_R;    /* save the timestamp */
                return (fallingEdge - risingEdge);     /* return the time difference */
            }
            break;
        case TIMER_W1:
            while(1)
            {
                INSERT_BIT(WTIMER1_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                while((READ_BIT(WTIMER1_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = WTIMER1_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(WTIMER1_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                    while((WTIMER1_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = WTIMER1_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER_W2:
            while(1)
            {
                INSERT_BIT(WTIMER2_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                while((READ_BIT(WTIMER2_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = WTIMER2_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(WTIMER2_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                    while((WTIMER2_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = WTIMER2_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER_W3:
            while(1)
            {
                INSERT_BIT(WTIMER3_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                while((READ_BIT(WTIMER3_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = WTIMER3_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(WTIMER3_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                    while((WTIMER3_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = WTIMER3_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER_W4:
            while(1)
            {
                INSERT_BIT(WTIMER4_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                while((READ_BIT(WTIMER4_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = WTIMER4_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(WTIMER4_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                    while((WTIMER4_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = WTIMER4_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        case TIMER_W5:
            while(1)
            {
                INSERT_BIT(WTIMER5_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                while((READ_BIT(WTIMER5_RIS_R, 2)) == 0);         /* wait till captured */
                if(DIO_ReadPin(ccp_pin))                        /*check if rising edge occurs */
                {
                    risingEdge = WTIMER5_TAR_R;     /* save the timestamp */
                    /* detect falling edge */
                    INSERT_BIT(WTIMER5_ICR_R, 2UL, 1UL);             /* clear WTIMER0A capture flag */
                    while((WTIMER5_RIS_R & (1<<2)) == 0);            /* wait till captured */
                    fallingEdge = WTIMER5_TAR_R;    /* save the timestamp */
                    return (fallingEdge - risingEdge) & 0x00FFFFFF; /* return the time difference */
                }
                return 0; /* return 0 if no signal */
            }
            break;
        default:
            break;
    }

}

