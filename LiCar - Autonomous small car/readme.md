# Small Autonomous Car with Tiva C TM4C123

## Table of Contents
- [Introduction](#introduction)
- [Project Overview](#project-overview)
- [Hardware Components](#hardware-components)
- [Software Setup](#software-setup)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgments](#acknowledgments)

## Introduction

This project involves building a small autonomous car using the Tiva C TM4C123 microcontroller. The car is designed to autonomously navigate its environment while avoiding obstacles and following lines.

![Autonomous Car](images/autonomous_car.png)

## Project Overview

The main function of this project is implemented in `main.c`, where the TivaWare library is utilized for sensor interfacing, motor control, and LCD display.

```c
/* TivaWare includes */
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/lcd.h"

/* Private includes */
#include "Tiva_DIO/Tiva_DIO.h"
#include "DC_motor/DC_motor.h"
#include "Tiva_GPTimers/Tiva_GPTimers.h"
#include "ultraSonic/ultraSonic.h"
#include "LCD_Driver/LCD_Driver.h"
#include "Sensors/Sensor.h"
