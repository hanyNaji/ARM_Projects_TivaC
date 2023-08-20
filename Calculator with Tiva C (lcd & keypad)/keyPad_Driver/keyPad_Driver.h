/*
 * keyPad_Driver.h
 *
 *  Created on: Aug 18, 2023
 *      Author: hanyt
 */

#ifndef KEYPAD_DRIVER_KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_KEYPAD_DRIVER_H_

#include "Tiva_DIO/Tiva_DIO.h"



#define WITH_INT        812
#define WITHOUT_INT     912

#define KP_MODE         WITH_INT


// keypad connected ports
#define KOUT_PORT    PORTE
#define KIN_PORT     PORTB

// keypad connected port interrupt status register (just put anything if not using interrupt)
#define K_MIS_R      GPIO_PORTB_MIS_R

// keypad connected pins of selected ports
#define KP_OUT1     PIN0
#define KP_OUT2     PIN1
#define KP_OUT3     PIN2
#define KP_OUT4     PIN3

#define KP_IN1     PIN0
#define KP_IN2     PIN1
#define KP_IN3     PIN2
#define KP_IN4     PIN3

// default key to check if any key is clicked on the keypad (if not using interrupt)
#define DEFAULT_K 'H'


extern unsigned  char symbol[4][4];   // symbols matrix for keypad chars
extern volatile unsigned char key_flag;   // flag used in the interrupt handler
//
extern unsigned char key_row;
extern unsigned char key_col;


void KeyPad_Init(void);
char KeyPad_Read(void);


#endif /* KEYPAD_DRIVER_KEYPAD_DRIVER_H_ */
