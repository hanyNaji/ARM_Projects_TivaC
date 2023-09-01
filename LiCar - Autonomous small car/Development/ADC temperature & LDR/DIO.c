
#include "DIO_INTRFACE.h"

#define portA_clock_EN 0X00000001
#define portB_clock_EN 0X00000002
#define portC_clock_EN 0X00000004
#define portD_clock_EN 0X00000008
#define portE_clock_EN 0X00000010
#define portF_clock_EN 0X00000020

void DIO_Initpin(DIO_Pin_type pin_num,DIO_PinStatus_type status)
{
    DIO_Port_type port=pin_num/8;
    u8 pin=pin_num%8;

    switch(status)
    {
        case (INLLUP):
        switch(port)
        {
        case (PA):
            {
                 SYSCTL_RCGCGPIO_R|=portA_clock_EN;
                 while((SYSCTL_PRGPIO_R&portA_clock_EN)==0);
                 GPIO_PORTA_LOCK_R=0X4C4F434B;
                 GPIO_PORTA_CR_R=0XFF;
                 CLEAR_BIT(GPIO_PORTA_DIR_R,pin);
                 SET_BIT(GPIO_PORTA_PUR_R,pin);
                 SET_BIT(GPIO_PORTA_DEN_R,pin);
                 break;
            }
        case (PB):
            {
                 SYSCTL_RCGCGPIO_R|=portB_clock_EN;
                 while((SYSCTL_PRGPIO_R&portB_clock_EN)==0);
                 GPIO_PORTB_LOCK_R=0X4C4F434B;
                 GPIO_PORTB_CR_R=0XFF;
                 CLEAR_BIT(GPIO_PORTB_DIR_R,pin);
                 SET_BIT(GPIO_PORTB_PUR_R,pin);
                 SET_BIT(GPIO_PORTB_DEN_R,pin);
                 break;
            }
        case (PC):
            {
                 SYSCTL_RCGCGPIO_R|=portC_clock_EN;
                 while((SYSCTL_PRGPIO_R&portC_clock_EN)==0);
                 GPIO_PORTC_LOCK_R=0X4C4F434B;
                 GPIO_PORTC_CR_R=0XFF;
                 CLEAR_BIT(GPIO_PORTC_DIR_R,pin);
                 SET_BIT(GPIO_PORTC_PUR_R,pin);
                 SET_BIT(GPIO_PORTC_DEN_R,pin);
                 break;
            }
        case (PD):
            {
                 SYSCTL_RCGCGPIO_R|=portD_clock_EN;
                 while((SYSCTL_PRGPIO_R&portD_clock_EN)==0);
                 GPIO_PORTD_LOCK_R=0X4C4F434B;
                 GPIO_PORTD_CR_R=0XFF;
                 CLEAR_BIT(GPIO_PORTD_DIR_R,pin);
                 SET_BIT(GPIO_PORTD_PUR_R,pin);
                 SET_BIT(GPIO_PORTD_DEN_R,pin);
                 break;
            }
        case (PE):
            {
                 SYSCTL_RCGCGPIO_R|=portE_clock_EN;
                 while((SYSCTL_PRGPIO_R&portE_clock_EN)==0);
                 GPIO_PORTE_LOCK_R=0X4C4F434B;
                 GPIO_PORTE_CR_R=0XFF;
                 CLEAR_BIT(GPIO_PORTE_DIR_R,pin);
                 SET_BIT(GPIO_PORTE_PUR_R,pin);
                 SET_BIT(GPIO_PORTE_DEN_R,pin);
                 break;
            }
        case (PF):
            {
                 SYSCTL_RCGCGPIO_R|=portF_clock_EN;
                 while((SYSCTL_PRGPIO_R&portF_clock_EN)==0);
                 GPIO_PORTF_LOCK_R=0X4C4F434B;
                 GPIO_PORTF_CR_R=0XFF;
                 CLEAR_BIT(GPIO_PORTF_DIR_R,pin);
                 SET_BIT(GPIO_PORTF_PUR_R,pin);
                 SET_BIT(GPIO_PORTF_DEN_R,pin);
                 break;
            }
        }
        case (INFREE):
        switch(port)
        {
         case (PA):
               {
               SYSCTL_RCGCGPIO_R|=portA_clock_EN;
               while((SYSCTL_PRGPIO_R&portA_clock_EN)==0);
               GPIO_PORTA_LOCK_R=0X4C4F434B;
               GPIO_PORTA_CR_R=0XFF;
               CLEAR_BIT(GPIO_PORTA_DIR_R,pin);
               CLEAR_BIT(GPIO_PORTA_PUR_R,pin);
               SET_BIT(GPIO_PORTA_DEN_R,pin);
               break;
               }
         case (PB):
              {
              SYSCTL_RCGCGPIO_R|=portB_clock_EN;
              while((SYSCTL_PRGPIO_R&portB_clock_EN)==0);
              GPIO_PORTB_LOCK_R=0X4C4F434B;
              GPIO_PORTB_CR_R=0XFF;
              CLEAR_BIT(GPIO_PORTB_DIR_R,pin);
              CLEAR_BIT(GPIO_PORTB_PUR_R,pin);
              SET_BIT(GPIO_PORTB_DEN_R,pin);
              break;
              }
         case (PC):
              {
               SYSCTL_RCGCGPIO_R|=portC_clock_EN;
               while((SYSCTL_PRGPIO_R&portC_clock_EN)==0);
               GPIO_PORTC_LOCK_R=0X4C4F434B;
               GPIO_PORTC_CR_R=0XFF;
               CLEAR_BIT(GPIO_PORTC_DIR_R,pin);
               CLEAR_BIT(GPIO_PORTC_PUR_R,pin);
               SET_BIT(GPIO_PORTC_DEN_R,pin);
               break;
              }
         case (PD):
              {
               SYSCTL_RCGCGPIO_R|=portD_clock_EN;
               while((SYSCTL_PRGPIO_R&portD_clock_EN)==0);
               GPIO_PORTD_LOCK_R=0X4C4F434B;
               GPIO_PORTD_CR_R=0XFF;
               CLEAR_BIT(GPIO_PORTD_DIR_R,pin);
               CLEAR_BIT(GPIO_PORTD_PUR_R,pin);
               SET_BIT(GPIO_PORTD_DEN_R,pin);
               break;
              }
         case (PE):
              {
               SYSCTL_RCGCGPIO_R|=portE_clock_EN;
               while((SYSCTL_PRGPIO_R&portE_clock_EN)==0);
               GPIO_PORTE_LOCK_R=0X4C4F434B;
               GPIO_PORTE_CR_R=0XFF;
               CLEAR_BIT(GPIO_PORTE_DIR_R,pin);
               CLEAR_BIT(GPIO_PORTE_PUR_R,pin);
               SET_BIT(GPIO_PORTE_DEN_R,pin);
               break;
              }
         case (PF):
              {
               SYSCTL_RCGCGPIO_R|=portF_clock_EN;
               while((SYSCTL_PRGPIO_R&portF_clock_EN)==0);
               GPIO_PORTF_LOCK_R=0X4C4F434B;
               GPIO_PORTF_CR_R=0XFF;
               CLEAR_BIT(GPIO_PORTF_DIR_R,pin);
               CLEAR_BIT(GPIO_PORTF_PUR_R,pin);
               SET_BIT(GPIO_PORTF_DEN_R,pin);
               break;
               }
        }

    case (OUTPUT):
    switch(port)
               {
               case (PA):
               {
                SYSCTL_RCGCGPIO_R|=portA_clock_EN;
                while((SYSCTL_PRGPIO_R&portA_clock_EN)==0);
                GPIO_PORTA_LOCK_R=0X4C4F434B;
                GPIO_PORTA_CR_R=0XFF;
                SET_BIT(GPIO_PORTA_DIR_R,pin);
                CLEAR_BIT(GPIO_PORTA_PUR_R,pin);
                SET_BIT(GPIO_PORTA_DEN_R,pin);
                break;
                }
                case (PB):
                {
                 SYSCTL_RCGCGPIO_R|=portB_clock_EN;
                 while((SYSCTL_PRGPIO_R&portB_clock_EN)==0);
                 GPIO_PORTB_LOCK_R=0X4C4F434B;
                 GPIO_PORTB_CR_R=0XFF;
                 SET_BIT(GPIO_PORTB_DIR_R,pin);
                 CLEAR_BIT(GPIO_PORTB_PUR_R,pin);
                 SET_BIT(GPIO_PORTB_DEN_R,pin);
                 break;
                 }
                 case (PC):
                 {
                  SYSCTL_RCGCGPIO_R|=portC_clock_EN;
                  while((SYSCTL_PRGPIO_R&portC_clock_EN)==0);
                  GPIO_PORTC_LOCK_R=0X4C4F434B;
                  GPIO_PORTC_CR_R=0XFF;
                  SET_BIT(GPIO_PORTC_DIR_R,pin);
                  CLEAR_BIT(GPIO_PORTC_PUR_R,pin);
                  SET_BIT(GPIO_PORTC_DEN_R,pin);
                  break;
                  }
                  case (PD):
                  {
                   SYSCTL_RCGCGPIO_R|=portD_clock_EN;
                   while((SYSCTL_PRGPIO_R&portD_clock_EN)==0);
                   GPIO_PORTD_LOCK_R=0X4C4F434B;
                   GPIO_PORTD_CR_R=0XFF;
                   SET_BIT(GPIO_PORTD_DIR_R,pin);
                   CLEAR_BIT(GPIO_PORTD_PUR_R,pin);
                   SET_BIT(GPIO_PORTD_DEN_R,pin);
                   break;
                  }
                  case (PE):
                  {
                   SYSCTL_RCGCGPIO_R|=portE_clock_EN;
                   while((SYSCTL_PRGPIO_R&portE_clock_EN)==0);
                   GPIO_PORTE_LOCK_R=0X4C4F434B;
                   GPIO_PORTE_CR_R=0XFF;
                   SET_BIT(GPIO_PORTE_DIR_R,pin);
                   CLEAR_BIT(GPIO_PORTE_PUR_R,pin);
                   SET_BIT(GPIO_PORTE_DEN_R,pin);
                   break;
                  }
                  case (PF):
                  {
                   SYSCTL_RCGCGPIO_R|=portF_clock_EN;
                   while((SYSCTL_PRGPIO_R&portF_clock_EN)==0);
                   GPIO_PORTF_LOCK_R=0X4C4F434B;
                   GPIO_PORTF_CR_R=0X1F;
                   SET_BIT(GPIO_PORTF_DIR_R,pin);
                   CLEAR_BIT(GPIO_PORTF_PUR_R,pin);
                   SET_BIT(GPIO_PORTF_DEN_R,pin);
                   break;
                  }
               }
        }
}

void DIO_WritePin(DIO_Pin_type pin_num ,DIO_Voltage_type volt)
{
    DIO_Port_type port=pin_num/8;
    u8 pin=pin_num%8;

	if(volt==HIGH)
	{
		switch(port)
		{
			case(PA):
			SET_BIT(GPIO_PORTA_DATA_R,pin);
			break;
			case(PB):
			SET_BIT(GPIO_PORTB_DATA_R,pin);
			break;
			case(PC):
			SET_BIT(GPIO_PORTC_DATA_R,pin);
			break;
			case(PD):
			SET_BIT(GPIO_PORTD_DATA_R,pin);
			break;
			case(PE):
            SET_BIT(GPIO_PORTE_DATA_R,pin);
            break;
            case(PF):
            SET_BIT(GPIO_PORTF_DATA_R,pin);
            break;
		}
	}
	else if (volt==LOW)
		{
			switch(port)
			{
				
			case(PA) :
			CLEAR_BIT(GPIO_PORTA_DATA_R,pin);
			break;
			
			case(PB) :
			CLEAR_BIT(GPIO_PORTB_DATA_R,pin);
			break;
			
			case(PC) :
			CLEAR_BIT(GPIO_PORTC_DATA_R,pin);
			break;
			
			case(PD) :
			CLEAR_BIT(GPIO_PORTD_DATA_R,pin);
			break;
			case(PE) :
            CLEAR_BIT(GPIO_PORTE_DATA_R,pin);
            break;
            case(PF) :
            CLEAR_BIT(GPIO_PORTF_DATA_R,pin);
            break;
			}
		}
	}
/*
DIO_Voltage_type DIO_ReadPin(DIO_Pin_type pin_num)
{
    DIO_Port_type port=pin_num/8;
    u8 pin=pin_num%8;
	DIO_Voltage_type volt=LOW;
		switch(port)
		{
			case(PA):
			volt = READ_BIT(GPIO_PORTA_DATA_R,pin);
			break;
			case(PB):
			volt = READ_BIT(GPIO_PORTB_DATA_R,pin);
			break;
			case(PC):
			volt = READ_BIT(GPIO_PORTC_DATA_R,pin);
			break;
			case(PD):
			volt = READ_BIT(GPIO_PORTD_DATA_R,pin);
			break;
			case(PE):
            volt = READ_BIT(GPIO_PORTE_DATA_R,pin);
            break;
            case(PF):
            volt = READ_BIT(GPIO_PORTF_DATA_R,pin);
            break;
		}
		return volt;
	}
*/
/*
void DIO_Init(void)
{
    DIO_Pin_type i;
    for(i=PINA0;i<TOTAL_PINS;i++)
    {
        DIO_InitPin(i,PinsStatusArray[i]);
    }
}*/
void DIO_WritePort(DIO_Port_type port ,u8 value)
{
    switch(port)
    {

        case (PA):
        GPIO_PORTA_DATA_R=value;
        break;

        case (PB):
        GPIO_PORTB_DATA_R=value;
        break;

        case (PC):
        GPIO_PORTC_DATA_R=value;
        break;

        case (PD):
        GPIO_PORTD_DATA_R=value;
        break;
        case (PE):
        GPIO_PORTE_DATA_R=value;
        break;
        case (PF):
        GPIO_PORTF_DATA_R=value;
        break;

    }
}


void DIO_TogglePin(DIO_Pin_type pin)
{
    DIO_Port_type port=pin/8;
    u8 pin_num=pin%8;
    switch(port)
    {

        case (PA):
            TOGGLE_BIT(GPIO_PORTA_DATA_R,pin_num);
        break;

        case (PB):
            TOGGLE_BIT(GPIO_PORTB_DATA_R,pin_num);
        break;

        case (PC):
            TOGGLE_BIT(GPIO_PORTC_DATA_R,pin_num);
        break;

        case (PD):
            TOGGLE_BIT(GPIO_PORTD_DATA_R,pin_num);
        break;
        case (PE):
            TOGGLE_BIT(GPIO_PORTE_DATA_R,pin_num);
        break;
        case (PF):
            TOGGLE_BIT(GPIO_PORTF_DATA_R,pin_num);
        break;

    }
}
