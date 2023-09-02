/*
 * DC_motor.h
 *
 *  Created on: Aug 31, 2023
 *      Author: hanyt
 */

#ifndef DC_MOTOR_DC_MOTOR_H_
#define DC_MOTOR_DC_MOTOR_H_



#include "Tiva_DIO/Tiva_DIO.h"
#include "Tiva_GPTimers/Tiva_GPTimers.h"



#define SPEED       40
#define ANGLE       25



typedef enum
{
    LEFT,
    RIGHT,
    FORWARD,
    BACKWARD
} CarDirType;

#define MOTOR1_PWM     (PF2)  /* MOTOR PWM 1 */    /* Data sheet page 1351 */
#define MOTOR2_PWM     (PB2)  /* MOTOR PWM 2 */

#define MOTOR1_CTL_1     (PB0)  /* MOTOR 1 control pin 1 */
#define MOTOR1_CTL_2     (PB1)  /* MOTOR 1 control pin 2 */
#define MOTOR2_CTL_1     (PB6)  /* MOTOR 2 control pin 1 */
#define MOTOR2_CTL_2     (PB7)  /* MOTOR 2 control pin 2 */



void PWM_init(GPT_Type timer_N);

void Duty_Cycle (GPT_Type timer_N, uint32_t pwm);

void turn_Car(CarDirType dir, uint8_t angle);

void turn_Left(void);

void move_Forward(uint32_t pwm);

void move_Backward(uint32_t pwm);


void PWM_PinInit(DIO_AllPINS_TYPE pin);

#endif /* DC_MOTOR_DC_MOTOR_H_ */
