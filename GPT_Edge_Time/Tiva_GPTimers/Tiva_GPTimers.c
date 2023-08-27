/*
 * Tiva_GPTimers.c
 *
 *  Created on: Aug 25, 2023
 *      Author: hany nagy
 */


#include "Tiva_GPTimers.h"





void Init(void)
{
    /*GPT_Init(GPTM_EdgeTimer.timer, GPTM_EdgeTimer.mode, GPTM_EdgeTimer.preScale);*/
}

void stop(void)
{
    INSERT_BIT(WTIMER0_CTL_R, 0, 0);
}


uint32_t GPTcapture_read(GPT_Type timer)
{
    uint32_t read = 0;
    switch(timer){
            case TIMER0:
                read = TIMER0_TAR_R;
                break;
            case TIMER1:
                read = TIMER1_TAR_R;
                break;
            case TIMER2:
                read = TIMER2_TAR_R;
                break;
            case TIMER3:
                read = TIMER3_TAR_R;
                break;
            case TIMER4:
                read = TIMER4_TAR_R;
                break;
            case TIMER5:
                read = TIMER5_TAR_R;
                break;
            case TIMER_W0:
                read = WTIMER0_TAR_R;
                break;
            case TIMER_W1:
                read = WTIMER1_TAR_R;
                break;
            case TIMER_W2:
                read = WTIMER2_TAR_R;
                break;
            case TIMER_W3:
                read = WTIMER3_TAR_R;
                break;
            case TIMER_W4:
                read = WTIMER4_TAR_R;
                break;
            case TIMER_W5:
                read = WTIMER5_TAR_R;
                break;
            default:
                break;
        }
    return read;
}


void GPT_Enable(GPT_Type timer)
{
    switch(timer){
            case TIMER0:
                INSERT_BIT(TIMER0_CTL_R, 0, 1);
                break;
            case TIMER1:
                INSERT_BIT(TIMER1_CTL_R, 0, 1);
                break;
            case TIMER2:
                INSERT_BIT(TIMER2_CTL_R, 0, 1);
                break;
            case TIMER3:
                INSERT_BIT(TIMER3_CTL_R, 0, 1);
                break;
            case TIMER4:
                INSERT_BIT(TIMER4_CTL_R, 0, 1);
                break;
            case TIMER5:
                INSERT_BIT(TIMER5_CTL_R, 0, 1);
                break;
            case TIMER_W0:
                INSERT_BIT(WTIMER0_CTL_R, 0, 1);
                break;
            case TIMER_W1:
                INSERT_BIT(WTIMER1_CTL_R, 0, 1);
                break;
            case TIMER_W2:
                INSERT_BIT(WTIMER2_CTL_R, 0, 1);
                break;
            case TIMER_W3:
                INSERT_BIT(WTIMER3_CTL_R, 0, 1);
                break;
            case TIMER_W4:
                INSERT_BIT(WTIMER4_CTL_R, 0, 1);
                break;
            case TIMER_W5:
                INSERT_BIT(WTIMER5_CTL_R, 0, 1);
                break;
            default:
                break;
        }

}


void GPT_Disable(GPT_Type timer)
{
    switch(timer){
        case TIMER0:
            INSERT_BIT(TIMER0_CTL_R, 0, 0);
            break;
        case TIMER1:
            INSERT_BIT(TIMER1_CTL_R, 0, 0);
            break;
        case TIMER2:
            INSERT_BIT(TIMER2_CTL_R, 0, 0);
            break;
        case TIMER3:
            INSERT_BIT(TIMER3_CTL_R, 0, 0);
            break;
        case TIMER4:
            INSERT_BIT(TIMER4_CTL_R, 0, 0);
            break;
        case TIMER5:
            INSERT_BIT(TIMER5_CTL_R, 0, 0);
            break;
        case TIMER_W0:
            INSERT_BIT(WTIMER0_CTL_R, 0, 0);
            break;
        case TIMER_W1:
            INSERT_BIT(WTIMER1_CTL_R, 0, 0);
            break;
        case TIMER_W2:
            INSERT_BIT(WTIMER2_CTL_R, 0, 0);
            break;
        case TIMER_W3:
            INSERT_BIT(WTIMER3_CTL_R, 0, 0);
            break;
        case TIMER_W4:
            INSERT_BIT(WTIMER4_CTL_R, 0, 0);
            break;
        case TIMER_W5:
            INSERT_BIT(WTIMER5_CTL_R, 0, 0);
            break;
        default:
            break;
    }

}

void GPT_Mode(GPT_Struct *st_timer)
{
    switch(st_timer->timer){
            case TIMER0:
                //
                break;
            case TIMER1:
                //
                break;
            case TIMER2:
                //
                break;
            case TIMER3:
                //
                break;
            case TIMER4:
                //
                break;
            case TIMER5:
                //
                break;
            case TIMER_W0:
                switch(st_timer->mode){
                    case ONE_SHOT:
                        break;
                    case PERIODIC:
                        break;
                    case CAPTURE:
                        INSERT_BIT(WTIMER0_CTL_R, 0, 0);
                        INSERT_BIT(WTIMER0_CFG_R, 2, 1);
                        INSERT_BIT(WTIMER0_TAMR_R, 2, st_timer->captureMode);
                        INSERT_BITS(WTIMER0_TAMR_R, st_timer->mode, 0, 2);
                        INSERT_BIT(WTIMER0_TAMR_R, 4, st_timer->dirMode);
                        INSERT_BITS(WTIMER0_CTL_R, st_timer->eventMode, 2, 2);
                        break;
                    default:
                        break;
                }
                break;
            case TIMER_W1:
                //
                break;
            case TIMER_W2:
                //
                break;
            case TIMER_W3:
                //
                break;
            case TIMER_W4:
                //
                break;
            case TIMER_W5:
                //
                break;
            default:
                break;
        }

}


void GPT_Init(GPT_Struct *st_timer)
{
    switch(st_timer->timer){
        case TIMER0:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 0, 1);
            GPT_Mode(st_timer);
            TIMER0_TAPR_R = st_timer->preScale;
            break;
        case TIMER1:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 1, 1);
            GPT_Mode(st_timer);
            TIMER1_TAPR_R = st_timer->preScale;
            break;
        case TIMER2:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 2, 1);
            GPT_Mode(st_timer);
            TIMER2_TAPR_R = st_timer->preScale;
            break;
        case TIMER3:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 3, 1);
            GPT_Mode(st_timer);
            TIMER3_TAPR_R = st_timer->preScale;
            break;
        case TIMER4:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 4, 1);
            GPT_Mode(st_timer);
            TIMER4_TAPR_R = st_timer->preScale;
            break;
        case TIMER5:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 5, 1);
            GPT_Mode(st_timer);
            TIMER5_TAPR_R = st_timer->preScale;
            break;
        case TIMER_W0:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 0, 1);
            GPT_Mode(st_timer);
            WTIMER0_TAPR_R = st_timer->preScale;
            break;
        case TIMER_W1:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 1, 1);
            GPT_Mode(st_timer);
            WTIMER1_TAPR_R = st_timer->preScale;
            break;
        case TIMER_W2:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 2, 1);
            GPT_Mode(st_timer);
            WTIMER2_TAPR_R = st_timer->preScale;
            break;
        case TIMER_W3:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 3, 1);
            GPT_Mode(st_timer);
            WTIMER3_TAPR_R = st_timer->preScale;
            break;
        case TIMER_W4:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 4, 1);
            GPT_Mode(st_timer);
            WTIMER4_TAPR_R = st_timer->preScale;
            break;
        case TIMER_W5:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 5, 1);
            GPT_Mode(st_timer);
            WTIMER5_TAPR_R = st_timer->preScale;
            break;
        default:
            break;
    }
}

void GPT_CCP_PinInit(DIO_AllPINS_TYPE pin)
{
    uint8_t Port = pin / 8;
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
