/*
 * ultraSonic.h
 *
 *  Created on: Aug 31, 2023
 *      Author: hanyt
 */

#ifndef ULTRASONIC_ULTRASONIC_H_
#define ULTRASONIC_ULTRASONIC_H_


#include "Tiva_DIO/Tiva_DIO.h"
#include "Tiva_GPTimers/Tiva_GPTimers.h"


void ultraSonic_Init(DIO_AllPINS_TYPE trigg, DIO_AllPINS_TYPE echoo);

uint8_t ultraSonic_ReadCM(void);



#endif /* ULTRASONIC_ULTRASONIC_H_ */
