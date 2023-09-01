

#ifndef DIO_INTRFACE_H_
#define DIO_INTRFACE_H_



#include "tm4c123gh6pm.h"
#include "stdTypes.h"
#include "Utils.h"
typedef enum{

    PINA0=0,
        PINA1=1,
        PINA2,
        PINA3,
        PINA4,
        PINA5,
        PINA6,
        PINA7,
        PINB0,
        PINB1,
        PINB2,
        PINB3,
        PINB4,
        PINB5,
        PINB6,
        PINB7,
        PINC0,
        PINC1,
        PINC2,
        PINC3,
        PINC4,
        PINC5,
        PINC6,
        PINC7,
        PIND0,
        PIND1,
        PIND2,
        PIND3,
        PIND4,
        PIND5,
        PIND6,
        PIND7,
        PINE0,
        PINE1,
        PINE2,
        PINE3,
        PINE4,
        PINE5,
        dummy1,
        dummy2,
        PINF0,
        PINF1,
        PINF2,
        PINF3,
        PINF4,
        PINF5,
        TOTAL_PINS
}DIO_Pin_type;

typedef enum{
	OUTPUT,
	INFREE,
	INLLUP
}DIO_PinStatus_type;

typedef enum{
	PA=0,
	PB,
	PC,
	PD,
	PE,
	PF
}DIO_Port_type;

typedef enum{
	LOW=0,
	HIGH
	
}DIO_Voltage_type;

extern void DIO_Initpin(DIO_Pin_type pin_num,DIO_PinStatus_type status);
extern void DIO_WritePin(DIO_Pin_type pin_num ,DIO_Voltage_type volt);
extern DIO_Voltage_type DIO_ReadPin(DIO_Pin_type pin_num);
//extern void DIO_Init(void);
//extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];

#endif /* DIO_INTRFACE_H_ */
