/*
 * ultraSonic.c
 *
 *  Created on: Aug 31, 2023
 *      Author: hanyt
 */


#include "ultraSonic.h"



static DIO_AllPINS_TYPE trig_pin ;
static DIO_AllPINS_TYPE echo_pin ;

/* Configuration for the GPTM_EdgeTimer */
GPT_Struct GPTM_EdgeTimer =
{
    TIMER_W0,           /* Timer type */
    0x00UL,             /* Pre-scale value */
    CAPTURE,            /* Timer mode */
    UNCONCAT,           /* Concatenation mode */
    EDGE_TIME,          /* Capture mode */
    CC_MODE,            /* Timer alternate mode */
    COUNT_UP,           /* Timer count direction */
    BOTH,               /* Event mode */
    ENABLE_INT,        /* Match interrupt type */
    WAIT_TAEN_BIT,      /* Start mode */
    DIS_SnapSh,         /* Snapshot mode */
    DIS_PWMInt,         /* PWM interrupt type */
    NEXT_CYCLE,         /* Match register update */
    CCP_LOW             /* PWM legacy operation */
};




void ultraSonic_Init(DIO_AllPINS_TYPE trigg, DIO_AllPINS_TYPE echoo)
{
    trig_pin = trigg;
    echo_pin = echoo;

    DIO_PORT_Init(trig_pin/8);
    DIO_PORT_Init(echo_pin/8);

    DIO_InitPin(trig_pin, OUTPUT);
    DIO_WritePin(trig_pin, LOW);
    DIO_InitPin(echo_pin, INFREE);

    /* Initialize GPT CCP pin */
    GPT_CCP_PinInit(echo_pin);

    /* Initialize and enable GPTM_EdgeTimer */
    GPT_Init(&GPTM_EdgeTimer);
    GPT_Enable(GPTM_EdgeTimer.timer);
}


uint8_t ultraSonic_ReadCM(void)
{
    uint8_t dist=0;
    uint32_t readtime=0;

    DIO_WritePin(trig_pin, LOW);
    _delay_us(2);
    DIO_WritePin(trig_pin, HIGH);
    _delay_us(10);
    DIO_WritePin(trig_pin, LOW);

    readtime = TimerACapture_PulseWidth(TIMER_W0, echo_pin);
    dist = ((readtime/16/2) / 29);

    return dist;
}
