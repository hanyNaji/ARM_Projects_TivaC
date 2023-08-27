
#include "Tiva_DIO/Tiva_DIO.h"
#include "./Tiva_GPTimers/Tiva_GPTimers.h"



#define LED_RED     (PF1)  /* PF3/LEDR */
#define LED_BLU     (PF2)  /* PF1/LEDB */
#define LED_GRN     (PF3)  /* PF2/LEDG */

#define SW1         (PF4)  /* PF4/SW1 */
#define SW2         (PF0)  /* PF0/SW2 */

#define CCP_PIN     (PC4)  /* for capture pin */

#define SEC_FREQ    16000000UL



GPT_Struct GPTM_EdgeTimer=
        {
         TIMER_W0,
         0x00,
         CAPTURE,
         UNCONCAT,
         EDGE_TIME,
         CC_MODE,
         COUNT_UP,
         NEGATIVE,
         DISABLE_INT,
         WAIT_TAEN_BIT,
         DIS_SnapSh,
         DIS_PWMInt,
         NEXT_CYCLE,
         CCP_LOW
        };



/* GPIO PORTF Interrupt handler */
void GPIOF_Handler(void)
{
    if (GPIO_PORTF_MIS_R & (uint32_t)(1U<<(SW1%8))) /* check if interrupt causes by PF4/SW1*/
    {
        GPIO_PORTF_ICR_R |= (unsigned long)(1U<<(SW1%8));
        DIO_TogglePin(SW2);
    }
    else {
        /* Do nothing for MISRA */
    }
}

volatile uint32_t read_old ;
volatile uint32_t read_new ;


/**
 * main.c
 */
void main(void)
{
    DIO_PORT_Init(PORTF);
    DIO_PORT_Init(PORTC);

    DIO_InitPin(LED_RED, OUTPUT);
    DIO_InitPin(LED_BLU, OUTPUT);
    DIO_InitPin(LED_GRN, OUTPUT);
    DIO_InitPin(CCP_PIN, INLLUP);
    DIO_InitPin(SW1, INLLUP);
    Inteupt_Edge_InitPin(SW1, LOW_EDGE);
    DIO_InitPin(SW2, OUTPUT);
    DIO_WritePin(SW2, HIGH);

    GPT_CCP_PinInit(CCP_PIN);    /* WT0CCP0 */

    GPT_Init(&GPTM_EdgeTimer);
    GPT_Enable(GPTM_EdgeTimer.timer);

    while(812)
    {
        if(!DIO_ReadPin(CCP_PIN))
        {
            read_new = GPTcapture_read(GPTM_EdgeTimer.timer);
            uint32_t time = 50;
            if(read_old){
                time = (read_new - read_old)/SEC_FREQ;
            }
            if(time <= 5 ){
                DIO_WritePin(LED_RED, HIGH);
                DIO_WritePin(LED_BLU, LOW);
                DIO_WritePin(LED_GRN, LOW);
            }
            else if(time <= 10 && time > 5 ){
                DIO_WritePin(LED_BLU, HIGH);
                DIO_WritePin(LED_GRN, LOW);
                DIO_WritePin(LED_RED, LOW);
            }
            else if(time <= 15 && time > 10){
                DIO_WritePin(LED_GRN, HIGH);
                DIO_WritePin(LED_BLU, LOW);
                DIO_WritePin(LED_RED, LOW);
            }
            else{
                /* */
            }
            DIO_TogglePin(SW2);
            read_old = read_new;
        }
        else{
            /* */
        }

    }
}









