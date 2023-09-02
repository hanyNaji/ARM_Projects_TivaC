/*
 * DC_motor.c
 *
 *  Created on: Aug 31, 2023
 *      Author: hany nagy
 */

#include "DC_motor.h"



void motors_Init(void)
{
    PWM_init(M1_TIMER);
    PWM_init(M2_TIMER);

    PWM_PinInit(MOTOR1_PWM);
    PWM_PinInit(MOTOR2_PWM);

    DIO_InitPin(MOTOR1_CTL_1, OUTPUT);
    DIO_InitPin(MOTOR1_CTL_2, OUTPUT);
    DIO_InitPin(MOTOR2_CTL_1, OUTPUT);
    DIO_InitPin(MOTOR2_CTL_2, OUTPUT);
}


void PWM_init(GPT_Type timer_N)
{

    switch(timer_N)
    {
        case TIMER0:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 0UL, 1UL);
            INSERT_BIT(TIMER0_CTL_R, 0, 0);
            TIMER0_CFG_R=0x4; /*Enable PWM*/

            TIMER0_TAMR_R|=0x2;
            INSERT_BIT(TIMER0_TAMR_R, 3, 1);
            INSERT_BIT(TIMER0_TAMR_R, 2, 0);

            INSERT_BIT(TIMER0_CTL_R, 6, 0);
            TIMER0_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER0_CTL_R, 0, 1);
            break;
        case TIMER1:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 1UL, 1UL);
            INSERT_BIT(TIMER1_CTL_R, 0, 0);
            TIMER1_CFG_R=0x4; /*Enable PWM*/

            TIMER1_TAMR_R|=0x2;
            INSERT_BIT(TIMER1_TAMR_R, 3, 1);
            INSERT_BIT(TIMER1_TAMR_R, 2, 0);

            INSERT_BIT(TIMER1_CTL_R, 6, 0);
            TIMER1_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER1_CTL_R, 0, 1);
            break;
        case TIMER2:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 2UL, 1UL);
            INSERT_BIT(TIMER2_CTL_R, 0, 0);
            TIMER2_CFG_R=0x4; /*Enable PWM*/

            TIMER2_TAMR_R|=0x2;
            INSERT_BIT(TIMER2_TAMR_R, 3, 1);
            INSERT_BIT(TIMER2_TAMR_R, 2, 0);

            INSERT_BIT(TIMER2_CTL_R, 6, 0);
            TIMER2_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER2_CTL_R, 0, 1);
            break;
        case TIMER3:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 3UL, 1UL);
            INSERT_BIT(TIMER3_CTL_R, 0, 0);
            TIMER3_CFG_R=0x4; /*Enable PWM*/

            TIMER3_TAMR_R|=0x2;
            INSERT_BIT(TIMER3_TAMR_R, 3, 1);
            INSERT_BIT(TIMER3_TAMR_R, 2, 0);

            INSERT_BIT(TIMER3_CTL_R, 6, 0);
            TIMER3_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER3_CTL_R, 0, 1);
            break;
        case TIMER4:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 4UL, 1UL);
            INSERT_BIT(TIMER4_CTL_R, 0, 0);
            TIMER4_CFG_R=0x4; /*Enable PWM*/

            TIMER4_TAMR_R|=0x2;
            INSERT_BIT(TIMER4_TAMR_R, 3, 1);
            INSERT_BIT(TIMER4_TAMR_R, 2, 0);

            INSERT_BIT(TIMER4_CTL_R, 6, 0);
            TIMER4_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER4_CTL_R, 0, 1);
            break;
        case TIMER5:
            INSERT_BIT(SYSCTL_RCGCTIMER_R, 5UL, 1UL);
            INSERT_BIT(TIMER5_CTL_R, 0, 0);
            TIMER5_CFG_R=0x4; /*Enable PWM*/

            TIMER5_TAMR_R|=0x2;
            INSERT_BIT(TIMER5_TAMR_R, 3, 1);
            INSERT_BIT(TIMER5_TAMR_R, 2, 0);

            INSERT_BIT(TIMER5_CTL_R, 6, 0);
            TIMER5_TAILR_R = 0X3E80;
            INSERT_BIT(TIMER5_CTL_R, 0, 1);
            break;
        case TIMER_W0:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 0UL, 1UL);
            INSERT_BIT(WTIMER0_CTL_R, 0, 0);
            WTIMER0_CFG_R=0x4; /*Enable PWM*/

            WTIMER0_TAMR_R|=0x2;
            INSERT_BIT(WTIMER0_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER0_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER0_CTL_R, 6, 0);
            WTIMER0_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER0_CTL_R, 0, 1);
            break;
        case TIMER_W1:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 1UL, 1UL);
            INSERT_BIT(WTIMER1_CTL_R, 0, 0);
            WTIMER1_CFG_R=0x4; /*Enable PWM*/

            WTIMER1_TAMR_R|=0x2;
            INSERT_BIT(WTIMER1_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER1_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER1_CTL_R, 6, 0);
            WTIMER1_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER1_CTL_R, 0, 1);
            break;
        case TIMER_W2:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 2UL, 1UL);
            INSERT_BIT(WTIMER2_CTL_R, 0, 0);
            WTIMER2_CFG_R=0x4; /*Enable PWM*/

            WTIMER2_TAMR_R|=0x2;
            INSERT_BIT(WTIMER2_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER2_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER2_CTL_R, 6, 0);
            WTIMER2_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER2_CTL_R, 0, 1);
            break;
        case TIMER_W3:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 3UL, 1UL);
            INSERT_BIT(WTIMER3_CTL_R, 0, 0);
            WTIMER3_CFG_R=0x4; /*Enable PWM*/

            WTIMER3_TAMR_R|=0x2;
            INSERT_BIT(WTIMER3_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER3_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER3_CTL_R, 6, 0);
            WTIMER3_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER3_CTL_R, 0, 1);
            break;
        case TIMER_W4:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 4UL, 1UL);
            INSERT_BIT(WTIMER4_CTL_R, 0, 0);
            WTIMER4_CFG_R=0x4; /*Enable PWM*/

            WTIMER4_TAMR_R|=0x2;
            INSERT_BIT(WTIMER4_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER4_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER4_CTL_R, 6, 0);
            WTIMER4_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER4_CTL_R, 0, 1);
            break;
        case TIMER_W5:
            INSERT_BIT(SYSCTL_RCGCWTIMER_R, 5UL, 1UL);
            INSERT_BIT(WTIMER5_CTL_R, 0, 0);
            WTIMER5_CFG_R=0x4; /*Enable PWM*/

            WTIMER5_TAMR_R|=0x2;
            INSERT_BIT(WTIMER5_TAMR_R, 3, 1);
            INSERT_BIT(WTIMER5_TAMR_R, 2, 0);

            INSERT_BIT(WTIMER5_CTL_R, 6, 0);
            WTIMER5_TAILR_R = 0X3E80;
            INSERT_BIT(WTIMER5_CTL_R, 0, 1);
            break;
        default:
            break;

    }
}

void PWM_PinInit(DIO_AllPINS_TYPE pin)
{
    uint8_t Port_N = (uint8_t) pin / 8;
    uint8_t pin_num = pin % 8;

    switch (Port_N)
    {
        case PORTA:
            DIO_PORT_Init(PORTA);
            GPIO_PORTA_AFSEL_R |= 0x04;         /* Data sheet page 671 */
            GPIO_PORTA_PCTL_R |= (0x07<<(pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        case PORTB:
            DIO_PORT_Init(PORTB);
            GPIO_PORTB_AFSEL_R |= 0x04;         /* Data sheet page 671 */
            GPIO_PORTB_PCTL_R |= (0x07<<(pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        case PORTC:
            DIO_PORT_Init(PORTC);
            GPIO_PORTC_AFSEL_R |= 0x04;         /* Data sheet page 671 */
            GPIO_PORTC_PCTL_R |= (0x07<<(pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        case PORTD:
            DIO_PORT_Init(PORTD);
            GPIO_PORTD_AFSEL_R |= 0x04;         /* Data sheet page 671 */
            GPIO_PORTD_PCTL_R |= (0x07<<(pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        case PORTE:
            DIO_PORT_Init(PORTE);
            GPIO_PORTE_AFSEL_R |= 0x04;         /* Data sheet page 671 */
            GPIO_PORTE_PCTL_R |= (0x07<<(pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        case PORTF:
            DIO_PORT_Init(PORTF);
            GPIO_PORTF_AFSEL_R |= 0x04;         /* Data sheet page 671 */
            GPIO_PORTF_PCTL_R |= (0x07<<(pin_num*4));     /* Data sheet page 688 */
            DIO_InitPin(pin, OUTPUT);
            break;
        default:
            break;
    }
}


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
    GPIO_PORTA_DATA_R |=(1<<3);
    GPIO_PORTA_DATA_R &=~(1<<2);
}


void turn_Car(CarDirType dir, uint8_t angle)
{

    switch (dir)
    {
        case LEFT:
            Duty_Cycle(M1_TIMER, SPEED);
            Duty_Cycle(M2_TIMER, 30);
            DIO_WritePin(MOTOR1_CTL_1, HIGH);
            DIO_WritePin(MOTOR1_CTL_2, LOW);
            DIO_WritePin(MOTOR2_CTL_1, HIGH);
            DIO_WritePin(MOTOR2_CTL_2, LOW);
            break;
        case RIGHT:
            Duty_Cycle(M1_TIMER, 30);
            Duty_Cycle(M2_TIMER, SPEED);
            DIO_WritePin(MOTOR1_CTL_1, LOW);
            DIO_WritePin(MOTOR1_CTL_2, HIGH);
            DIO_WritePin(MOTOR2_CTL_1, LOW);
            DIO_WritePin(MOTOR2_CTL_2, HIGH);
            break;
        case REVERSE:
            Duty_Cycle(M1_TIMER, 50);
            Duty_Cycle(M2_TIMER, 50);
            DIO_WritePin(MOTOR1_CTL_1, LOW);
            DIO_WritePin(MOTOR1_CTL_2, HIGH);
            DIO_WritePin(MOTOR2_CTL_1, LOW);
            DIO_WritePin(MOTOR2_CTL_2, HIGH);
            break;
        default:
            return 0x00;
            break;
    }
    _delay_ms(30 * angle/10);

    Duty_Cycle(M1_TIMER, 30);
    Duty_Cycle(M2_TIMER, 30);
}


void move_Forward(uint32_t pwm)
{
    Duty_Cycle (M1_TIMER, pwm);
    Duty_Cycle (M2_TIMER, pwm);
    DIO_WritePin(MOTOR1_CTL_1, LOW);
    DIO_WritePin(MOTOR1_CTL_2, HIGH);
    DIO_WritePin(MOTOR2_CTL_1, HIGH);
    DIO_WritePin(MOTOR2_CTL_2, LOW);
}

void move_Backward(uint32_t pwm)
{

    Duty_Cycle (M1_TIMER, pwm);
    Duty_Cycle (M2_TIMER, pwm);
    DIO_WritePin(MOTOR1_CTL_1, HIGH);
    DIO_WritePin(MOTOR1_CTL_2, LOW);
    DIO_WritePin(MOTOR2_CTL_1, LOW);
    DIO_WritePin(MOTOR2_CTL_2, HIGH);
}


void Duty_Cycle (GPT_Type timer_N, uint32_t pwm)
{
        switch(timer_N)
        {
            case TIMER0:
                TIMER0_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER1:
                TIMER1_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER2:
                TIMER2_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER3:
                TIMER3_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER4:
                TIMER4_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER5:
                TIMER5_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W0:
                WTIMER0_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W1:
                WTIMER1_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W2:
                WTIMER2_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W3:
                WTIMER3_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W4:
                WTIMER4_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            case TIMER_W5:
                WTIMER5_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
                break;
            default:
                break;
        }
}


void PWM_Freq_KHZ(uint16_t freq)
{
    if (freq==0);
    else
    {
        uint16_t Ttotal=1000/freq;
        if (Ttotal>=1)
        {
            TIMER1_TAMATCHR_R=Ttotal-1;
        }
        else TIMER1_TAMATCHR_R=0;

    }
}




