/*
 * Sensor.h
 *
 *  Created on: 31 Aug 2023
 *      Author: Amr Al-Kayal
 */

#ifndef SENSOR_H_
#define SENSOR_H_


#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"

void LDR_Right(void);
void READ_Right(uint32_t * Copy_Parmeter);
void LDR_Left(void);
void READ_LEFT(uint32_t * Copy_Parmeter);


void temp_Init(void);
uint32_t Temp_Read(void);
//void temp_Init();
void LDR_L_Inti();
void LDR_R_Inti();


#endif /* SENSOR_H_ */
