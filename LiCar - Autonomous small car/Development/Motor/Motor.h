/*
 * Motor.h
 *
 *  Created on: Aug 31, 2023
 *      Author: EUI-Support
 */

#ifndef MOTOR_H_
#define MOTOR_H_





void PWM_init(void);
void Duty_Cycle (f32 pwm);
void Turn_OtherDirection(void);
void Turn_oneDirection(void);
void Delay_ms(int time_ms);






#endif /* MOTOR_H_ */
