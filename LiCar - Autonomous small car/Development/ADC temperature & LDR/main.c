

#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/lcd.h"


#include "LCD.h"
#include "DIO_INTRFACE.h"
#include "stdTypes.h"
#include "Utils.h"
#include "Sensor.h"


void LCD_Display(uint32_t temp,uint32_t left,uint32_t right);


void Initpins_project(void);


void main(void)
{


    Initpins_project();
    uint32_t temp;
    LDR_Left();
    LDR_Right();
    temp_Inti();
    // The ADC0 peripheral must be enabled for use.

    LCD_WriteString("ADC & LDR");
    _delay_ms(500);
    LCD_Clear();
    while(1)
    {
        temp=Temp_Read();
        READ_LEFT(&left);
        READ_Right(&right);
        LCD_Display(temp,left,right);



    }
}



void LCD_Display(uint32_t temp,uint32_t left,uint32_t right)
{
    LCD_GoTo(0, 1);
    LCD_WriteString("Temp = ");
    LCD_WriteNumber_4D(temp);
    LCD_GoTo(1, 0);
    LCD_WriteString("LDR:");
    LCD_WriteNumber_4D(left);
    LCD_WriteString(",:");
    LCD_WriteNumber_4D(right);

}

void Initpins_project(void)
{

    DIO_Initpin(PINA5, OUTPUT);
    DIO_Initpin(PINA6, OUTPUT);
    DIO_Initpin(PINA7, OUTPUT);
    DIO_Initpin(PINC6, OUTPUT);
    DIO_Initpin(PINA4, OUTPUT);
    DIO_Initpin(PINA3, OUTPUT);
    DIO_Initpin(PINA2, OUTPUT);
    LCD_Init();
}


