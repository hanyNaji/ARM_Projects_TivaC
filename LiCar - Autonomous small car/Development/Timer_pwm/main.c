

/**
 * main.c
 */
#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "std_types.h"

void Duty_Cycle (float32 pwm);

int main(void)
{

    SYSCTL_RCGC1_R |= (1<<17);
    DIO_init(PORTF, 0, 0x04);
    GPIO_PORTF_AFSEL_R|=0x04;
    GPIO_PORTF_PCTL_R|= (0x07<<8);
    CLR_BIT(TIMER1_CTL_R,0);
    TIMER1_CFG_R=0x4;
    TIMER1_TAMR_R|=0x2;
    SET_BIT(TIMER1_TAMR_R,3);
    CLR_BIT(TIMER1_TAMR_R,2);
    CLR_BIT(TIMER1_CTL_R,6);
    Duty_Cycle (10);
    TIMER1_TAILR_R=0X3E80;
    SET_BIT(TIMER1_CTL_R,0);

    while (1)
    {

    }

}
void Duty_Cycle (float32 pwm)
{
    TIMER1_TAMATCHR_R = 16000 - (pwm/100.0)*16000;
}
