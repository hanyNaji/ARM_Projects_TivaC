/*
 * Tiva_GPTimers.h
 *
 *  Created on: Aug 25, 2023
 *      Author: hany nagy
 *
 */

#ifndef TIVA_GPT_TIVA_GPTIMERS_H_
#define TIVA_GPT_TIVA_GPTIMERS_H_

#include "Tiva_DIO/Tiva_DIO.h"


/* Enumeration of available General-Purpose Timers */
typedef enum{
    TIMER0,
    TIMER1,
    TIMER2,
    TIMER3,
    TIMER4,
    TIMER5,
    TIMER_W0,
    TIMER_W1,
    TIMER_W2,
    TIMER_W3,
    TIMER_W4,
    TIMER_W5
}GPT_Type;  /*TM4C123 Timers*/


typedef enum{
    M_RESERVED=0x0,
    ONE_SHOT=0x1,
    PERIODIC=0x2,
    CAPTURE=0x3,
}GPT_ModeType;  /*GPTM Timer Mode*/


typedef enum{
    UNCONCAT,
    CONCAT
}GPT_ConcatType;   /*GPTMCFG values 16/32 -- 32/64*/


typedef enum{
    EDGE_COUNT,
    EDGE_TIME
}GPT_CMType;   /*GPTM Timer Capture Mode*/


typedef enum{
    CC_MODE,
    PWM_MODE
}GPT_alterModeSelType; /*GPTM Timer Alternate Mode Select*/

typedef enum{
    COUNT_DWON,
    COUNT_UP
}GPT_CountDirType;  /*GPTM Timer Count Direction*/


typedef enum{
    DISABLE_INT,
    ENABLE_INT
}GPT_MatchIntType;  /*GPTM Timer Match Interrupt Enable*/

typedef enum{
    BEGIN_ON_EN,
    WAIT_TAEN_BIT
}GPT_WaitOnTrigerType;  /*GPTM Timer Wait-on-Trigger*/


typedef enum{
    DIS_SnapSh,
    EN_SnapSh
}GPT_SnapShotType;  /*GPTM Timer Snap-Shot Mode*/


typedef enum{
    DIS_PWMInt,
    EN_PWMInt
}GPT_PWMIntType;   /*GPTM Timer PWM Interrupt Enable*/


typedef enum{
    NEXT_CYCLE,
    NEXT_TIMEOUT
}GPT_MatchRegUpdateType;   /*GPTM Timer Match Register Update*/


typedef enum{
    CCP_LOW,
    CCP_HIGH
}GPT_PWMLegacyOpType;   /*GPTM Timer PWM Legacy Operation*/


typedef enum{
    POSITIVE= 0x01,
    NEGATIVE= 0x02,
    EM_RESERVED= 0x03,
    BOTH= 0x04
}GPT_EventModeType;   /*GPTM Timer Event Mode*/

/*Structure to configure GPT timer settings*/
typedef struct{
    GPT_Type timer;
    uint8_t preScale;
    GPT_ModeType mode;
    GPT_ConcatType concat;
    GPT_CMType captureMode;
    GPT_alterModeSelType alterModeSelect;
    GPT_CountDirType dirMode;
    GPT_EventModeType eventMode;
    GPT_MatchIntType intType;
    GPT_WaitOnTrigerType startMode;
    GPT_SnapShotType snapShot;
    GPT_PWMIntType PWMInt;
    GPT_MatchRegUpdateType regUpdate;
    GPT_PWMLegacyOpType PWMLegOp;
}GPT_Struct;


typedef struct{
    GPT_Type timer;
    uint8_t preScale;
    GPT_ModeType mode;
    GPT_ConcatType concat;
    GPT_CMType captureMode;
    GPT_CountDirType dirMode;
    GPT_EventModeType eventMode;
}GPT_EdgeTime_Struct;

/* Global variable to configure an edge-timed GPT instance */
extern GPT_Struct GPTM_EdgeTimer;

/**************** Function Prototypes *****************/

/**
 * @brief Enables a specified GPT timer.
 */
void GPT_Enable(GPT_Type timer);

/**
 * @brief Initializes a GPT timer using the provided configuration.
 */
void GPT_Init(GPT_Struct *st_timer);

/**
 * @brief Sets the operating mode of a GPT timer.
 */
void GPT_Mode(GPT_Struct *st_timer);

/**
 * @brief Stops a GPT timer.
 */
void stop(void);

/**
 * @brief Reads the captured value from a GPT timer.
 */
uint32_t GPTcapture_read(GPT_Type timer);

/**
 * @brief Initializes a GPT CCP pin.
 */
void GPT_CCP_PinInit(DIO_AllPINS_TYPE pin);

#endif /* TIVA_GPT_TIVA_GPT_H_ */
