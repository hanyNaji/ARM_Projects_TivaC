

/**
 * main.c
 *
 *
 */

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "GPIO_Interface.h"
#include "Motor.h"
#include "TM4C123GH6PM.h"






int main(void)
{

//    GPIO_void_Init();


    SYSCTL_RCGCGPIO_R |= 0x3F;
    GPIO_PORTF_LOCK_R = 0x4C4F434B;

//    SYSCTL_RCGC1_R |= (1<<17)|(1<<19);
    SYSCTL_RCGCTIMER_R |= 0x0F;

    GPIO_PORTF_AFSEL_R |= 0x04;         /* Data sheet page 671 */
    GPIO_PORTF_PCTL_R |= (0x07<<8);     /* Data sheet page 688 */


    CLR_BIT(TIMER1_CTL_R,0); // Enable PWM
    TIMER1_CFG_R=0x4;

    TIMER1_TAMR_R|=0x2;
    SET_BIT(TIMER1_TAMR_R,3);
    CLR_BIT(TIMER1_TAMR_R,2);

    CLR_BIT(TIMER1_CTL_R,6);

    TIMER1_TAILR_R=0X3E80;

    SET_BIT(TIMER1_CTL_R,0);

    SYSCTL_RCGCGPIO_R |= 0x20;   /* enable clock to PORTF */
    GPIO_PORTF_DIR_R |= (1<<2);            /* pin digital */
    GPIO_PORTF_DEN_R |= (1<<2);
    GPIO_PORTF_DATA_R |=(1<<2);

//////////////////////////////////////////////////
    GPIO_PORTB_LOCK_R = 0x4C4F434B;
    GPIO_PORTB_AFSEL_R |= 0x04;         /* Data sheet page 671 */
    GPIO_PORTB_PCTL_R |= (0x07<<8);     /* Data sheet page 688 */

    CLR_BIT(TIMER3_CTL_R,0); // Enable PWM
    TIMER3_CFG_R=0x4;

    TIMER3_TAMR_R |=0x2;
    SET_BIT(TIMER3_TAMR_R,3);
    CLR_BIT(TIMER3_TAMR_R,2);

    CLR_BIT(TIMER3_CTL_R,6);

    TIMER3_TAILR_R=0X3E80;

    SET_BIT(TIMER3_CTL_R,0);

    SYSCTL_RCGCGPIO_R |= 0x02;   /* enable clock to PORTB */
    GPIO_PORTB_DIR_R |= (1<<2);            /* pin digital */
    GPIO_PORTB_DEN_R |= (1<<2);
    GPIO_PORTB_DATA_R |=(1<<2);

    for(;;)
    {
//        Turn_oneDirection ();

        for(int i = 1; i<100 ; i++){
            Delay_ms(5);
            Duty_Cycle(i);
        }

        Delay_ms(10);

        for(int i = 100; i>0 ; i--){
            Delay_ms(5);
            Duty_Cycle(i);
        }
        Delay_ms(10);
    }
}



