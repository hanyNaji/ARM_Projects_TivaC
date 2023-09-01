/*
 * LCD.h
 *
 * Created: 6/18/2023 3:55:37 PM
 *  Author: Developer
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "StdTypes.h"
#include "DIO_INTRFACE.h"
#include "Utils.h"
#include "delay.h"

/******************************** CONFIG ************************************/


#define _8_BIT 0
#define _4_BIT 1
#define LCD_MODE _4_BIT
//8_Bit Mode :
#define LCD_PORT  PB
#define FUNCTION_SET_8BIT 0x38
#define FUNCTION_SET_4BIT 0x28
#define DISPLAY_CONTROL 0x0E
#define DISPLAY_CLEAR 0X01
#define ENTRY_MODE_SET 0x06
//4_Bit Mode :
#define D4          PINA2
#define D5          PINA3
#define D6          PINA4
#define D7          PINB6

#define RS  PINA5
#define RW  PINA6
#define EN  PINA7
/***************************************************************************/

/******************************** FUNCTIONS ********************************/
void LCD_WriteData(u8 data);
void LCD_WriteCommand(u8 command);
void LCD_Init(void);
/********************************* SERVICES *******************************/
void LCD_WriteString(u8 str[]);
void LCD_WriteNumber(s64 num);
void LCD_Clear(void);
void LCD_GoTo(u8 y,u8 x);
void LCD_CreateCharacter(u8* pattern,u8 address);
void LCD_WriteChar(u8 ch);
void LCD_WriteNumberInBinary(u8 num);
void LCD_WriteNumber_4D(u16 num);
void LCD_WriteNumber_2D(u16 num);

#endif /* LCD_H_ */
