/*
 * keyPad_Driver.c
 *
 *  Created on: Aug 18, 2023
 *      Author: hanyt
 */


#include "keyPad_Driver.h"

volatile unsigned char key_flag=0;  // flag used in the interrupt handler
unsigned char key_row=0;
unsigned char key_col=0;

/* Array of 4x4 to define characters which will be print on specific key pressed */
unsigned  char symbol[4][4] = {{ '1', '2',  '3', '+'},
                               { '4', '5',  '6', '-'},
                               { '7', '8',  '9', '*'},
                               { '.', '0',  '=', '/'}};

#if KP_MODE == WITHOUT_INT



/********************* with GPIOS without interrupt *********************/
/*
 * Function KeyPad_Init (void) (void)
 * Initialize the key pad 4*4
 */
void KeyPad_Init(void)
{
    // input pins to read data from
    DIO_InitPin(KIN_PORT, KP_IN1, INLLUP);
    DIO_InitPin(KIN_PORT, KP_IN2, INLLUP);
    DIO_InitPin(KIN_PORT, KP_IN3, INLLUP);
    DIO_InitPin(KIN_PORT, KP_IN4, INLLUP);

    // output pins to apply voltage to read it from inputs
    DIO_InitPin(KOUT_PORT, KP_OUT1, OUTPUT);
    DIO_InitPin(KOUT_PORT, KP_OUT2, OUTPUT);
    DIO_InitPin(KOUT_PORT, KP_OUT3, OUTPUT);
    DIO_InitPin(KOUT_PORT, KP_OUT4, OUTPUT);
}

/*
 * Function KeyPad_Read (unsigned  char) (void)
 * Return: read char if found else return DEFAULT_K
 */
char KeyPad_Read(void)
{
    char key = DEFAULT_K;

    DIO_WritePin(KOUT_PORT, KP_OUT1, HIGH);
    DIO_WritePin(KOUT_PORT, KP_OUT2, HIGH);
    DIO_WritePin(KOUT_PORT, KP_OUT3, HIGH);
    DIO_WritePin(KOUT_PORT, KP_OUT4, HIGH);

    for (int r= 0; r < 4; r++) {
        DIO_WritePin(KOUT_PORT, KP_OUT1+r, LOW);
        for (int c= 0; c < 4; c++) {
            if(!DIO_ReadPin(KIN_PORT, KP_IN1+c))
            {
                key = symbol[r][c];
                while(!DIO_ReadPin(KIN_PORT, KP_IN1+c));
            }
        }
        DIO_WritePin(KOUT_PORT, KP_OUT1+r, HIGH);
    }

    return key;
}
/************************************************************************/
#endif  // WITHOUT_INT

#if KP_MODE == WITH_INT
/********************* with interrupt *********************/
/*
 * Function KeyPad_Init (void) (void)
 * Initialize the key pad 4*4
 * Using interrupt
 */
void KeyPad_Init(void)
{
    // input pins to read data from and using interrupt to read
    DIO_InitPin(KIN_PORT, KP_IN1, INLLUP);
    Inteupt_Edge_InitPin(KIN_PORT, KP_IN1, LOW_EDGE);
    DIO_InitPin(KIN_PORT, KP_IN2, INLLUP);
    Inteupt_Edge_InitPin(KIN_PORT, KP_IN2, LOW_EDGE);
    DIO_InitPin(KIN_PORT, KP_IN3, INLLUP);
    Inteupt_Edge_InitPin(KIN_PORT, KP_IN3, LOW_EDGE);
    DIO_InitPin(KIN_PORT, KP_IN4, INLLUP);
    Inteupt_Edge_InitPin(KIN_PORT, KP_IN4, LOW_EDGE);

    // output pins to apply voltage to read it from inputs
    DIO_InitPin(KOUT_PORT, KP_OUT1, OUTPUT);
    DIO_InitPin(KOUT_PORT, KP_OUT2, OUTPUT);
    DIO_InitPin(KOUT_PORT, KP_OUT3, OUTPUT);
    DIO_InitPin(KOUT_PORT, KP_OUT4, OUTPUT);

    DIO_WritePin(KOUT_PORT, KP_OUT1, HIGH);
    DIO_WritePin(KOUT_PORT, KP_OUT2, HIGH);
    DIO_WritePin(KOUT_PORT, KP_OUT3, HIGH);
    DIO_WritePin(KOUT_PORT, KP_OUT4, HIGH);
}




/*
 * Function KeyPad_Read (unsigned  char) (void)
 * Return: DEFAULT_K if any key pressed else -1
 * Using interrupt
 */
char KeyPad_Read(void)
{
    for (int r= 0; r < 4; r++) {
        DIO_WritePin(KOUT_PORT, KP_OUT1+r, LOW);
        key_row = r;
        while(!DIO_ReadPin(KIN_PORT, KP_IN1));
        while(!DIO_ReadPin(KIN_PORT, KP_IN2));
        while(!DIO_ReadPin(KIN_PORT, KP_IN3));
        while(!DIO_ReadPin(KIN_PORT, KP_IN4));
        DIO_WritePin(KOUT_PORT, KP_OUT1+r, HIGH);
        if(key_flag) return 1;
    }
    return 0;
}

/************************************************************************/
#endif  // WITH_INT


