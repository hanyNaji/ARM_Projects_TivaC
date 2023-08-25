/*
 * keyPad_Driver.h
 *
 *  Created on: Aug 18, 2023
 *      Author: hany nagy
 */

#ifndef KEYPAD_DRIVER_KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_KEYPAD_DRIVER_H_

#include "Tiva_DIO/Tiva_DIO.h"

/* Constants*/

#define WITH_INT        812
#define WITHOUT_INT     912

#define KP_MODE         WITH_INT

/* Keypad connected ports */
#define KOUT_PORT    PORTE
#define KIN_PORT     PORTB

/* Keypad connected port interrupt status register (used if using interrupt) */
#define K_MIS_R      GPIO_PORTB_MIS_R

/* Keypad connected pins of selected ports */
#define KP_OUT1     PE0
#define KP_OUT2     PE1
#define KP_OUT3     PE2
#define KP_OUT4     PE3

#define KP_IN1     PB0
#define KP_IN2     PB1
#define KP_IN3     PB2
#define KP_IN4     PB3

/* Default key value returned when no key is pressed (used if not using interrupt) */
#define DEFAULT_K 'H'

/* External Variables*/

extern unsigned char symbol[4][4];   /* Symbols matrix for keypad characters */
extern volatile unsigned char key_flag;   /* Flag used in the interrupt handler */

extern unsigned char key_row;
extern unsigned char key_col;

/* Function Prototypes*/

/**
 * @brief Initializes the keypad.
 */
void KeyPad_Init(void);

/**
 * @brief Reads a character from the keypad.
 *
 * @return The character corresponding to the pressed key.
 */
char KeyPad_Read(void);

#endif /* KEYPAD_DRIVER_KEYPAD_DRIVER_H_ */
