/*
 * LCD.c
 *
 * Created: 6/18/2023 3:55:24 PM
 *  Author: Developer
 */ 
#include "LCD.h"
#if(LCD_MODE==_8_BIT)

    void LCD_Writecommand(u8 command)
    {
        DIO_WritePin(RS,LOW);
        DIO_WritePin(RW,LOW);
        DIO_WritePort(LCD_PORT,command);
        DIO_WritePin(EN,HIGH);
        _delay_ms(2);
        DIO_WritePin(EN,LOW);
        _delay_ms(2);

    }

    void LCD_Writedate(u8 data)
    {
        DIO_WritePin(RS,HIGH);
        DIO_WritePin(RW,LOW);
        DIO_WritePort(LCD_PORT,data);
        DIO_WritePin(EN,HIGH);
        _delay_ms(2);
        DIO_WritePin(EN,LOW);
        _delay_ms(2);

    }

    void LCD_Init(void)
    {
        _delay_ms(50);
        LCD_Writecommand(0x38);
        _delay_ms(1);
        LCD_Writecommand(0x0f);//cursor
        _delay_ms(1);
        LCD_Writecommand(0x01);//clear
        _delay_ms(2);
        LCD_Writecommand(0x06);//DDRAM ADDRESS INCRE
        _delay_ms(2);
    }
void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	DIO_WritePort(LCD_PORT,command);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

#elif(LCD_MODE==_4_BIT)
void LCD_WriteCommand(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(RW,LOW);
	DIO_WritePin(D4,READ_BIT(command,4));
	DIO_WritePin(D5,READ_BIT(command,5));
	DIO_WritePin(D6,READ_BIT(command,6));
	DIO_WritePin(D7,READ_BIT(command,7));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D4,READ_BIT(command,0));
	DIO_WritePin(D5,READ_BIT(command,1));
	DIO_WritePin(D6,READ_BIT(command,2));
	DIO_WritePin(D7,READ_BIT(command,3));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(RW,LOW);
	DIO_WritePin(D4,READ_BIT(data,4));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	_delay_ms(1);
	LCD_WriteCommand(FUNCTION_SET_4BIT);//4bitMode, 2 lines, 5*7
	_delay_ms(1);
	LCD_WriteCommand(DISPLAY_CONTROL);//cursor, 0x0c , 0x0e , 0x0f
	_delay_ms(1);
	LCD_WriteCommand(DISPLAY_CLEAR);//CLEAR SCREEN
	_delay_ms(2);
	LCD_WriteCommand(ENTRY_MODE_SET);//increase DD RAM address
	_delay_ms(1);
}
#endif
/********************************* SERVICES *******************************/
void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}
void LCD_WriteNumberInBinary(u8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		//LCD_WriteData(((num>>i)&1)+'0');
		LCD_WriteData(READ_BIT(num,i)+'0');
	}
}
void LCD_Clear(void)
{
	LCD_WriteCommand(DISPLAY_CLEAR);
}
void LCD_GoTo(u8 y,u8 x)
{
	u8 command = 0x80;
	if (y==0)
	{
		command += x;
		LCD_WriteCommand(command);
	}
	else if (y==1)
	{
		command += (x+0x40);
		LCD_WriteCommand(command);
	}
}
void LCD_CreateCharacter(u8* pattern,u8 address)
{
	u8 i,command =0x40;
	LCD_WriteCommand(command+address*8);
	for (i=0;i<8;i++)
	{
		LCD_WriteData(pattern[i]);
	}
}
void LCD_WriteString(u8 str[])
{
	u8 i;
	for(i=0;str[i];i++)
	{
		LCD_WriteData(str[i]);
	}
}
void LCD_WriteNumber(s64 num)
{
	
	u8 i, rem, arr[16]={0};
	if (num==0)
	{
		LCD_WriteData('0');
	}
	else
	{
		if (num<0)
		{
			num*=-1;
			LCD_WriteData('-');
		}
		while(num>0)
		{
			rem = num%10;
			arr[i]= rem+'0';
			i++;
			num/=10;
		}
		i;
		for(i;i>0;i--)
		{
			LCD_WriteData(arr[i-1]);
		}
	}
	
}
void LCD_WriteNumber_4D(u16 num)
{
	LCD_WriteData((num%10000)/1000+'0');
	LCD_WriteData((num%1000)/100+'0');
	LCD_WriteData((num%100)/10+'0');
	LCD_WriteData((num%10)/1+'0');
}

void LCD_WriteNumber_2D(u16 num)
{

    LCD_WriteData((num%100)/10+'0');
    LCD_WriteData((num%10)/1+'0');
}


