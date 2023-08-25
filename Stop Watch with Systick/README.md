# Stopwatch Project using SysTick of EK-TM4C123 Tiva C

This repository contains the source code for a stopwatch project implemented using the SysTick timer of the TM4C123 microcontroller. The stopwatch displays elapsed time on an LCD screen.

<img src="https://github.com/hanyNaji/ARM_Projects_TivaC/blob/main/Stop%20Watch%20with%20Systick/data/stopwatch1.jpeg" alt="Alt text" title="sw1">
<img src="https://github.com/hanyNaji/ARM_Projects_TivaC/blob/main/Stop%20Watch%20with%20Systick/data/stopwatch3.jpeg" alt="Alt text" title="sw2">

## Features

- Elapsed time measurement with hours, minutes, seconds, and moments.
- Start, Pause functionality.
- Displaying elapsed time on an LCD screen.
- Utilizing SysTick timer for accurate timekeeping.
- Interrupt-based user input handling.

## Hardware Requirements

- TM4C123 microcontroller board (or similar).
- LCD module for displaying the elapsed time.
- Necessary circuit connections (wires, resistors, etc.).

## Project Structure

- `LCD_Driver`: A library to interface with the LCD module.
- `Tiva_DIO`: A library to configure and control digital I/O pins on the TM4C123.
- `main.c`: The main application source code implementing the stopwatch logic.
- `tm4c123gh6pm.cmd`: Linker script for the TM4C123 microcontroller.
- `tm4c123gh6pm_startup_ccs.c`: Startup code for the Code Composer Studio environment.

## Getting Started

1. Set up your development environment and ensure you have the necessary tools and libraries installed.
2. Connect the TM4C123 board and LCD module as per your circuit diagram.
3. Clone or download this repository.
4. Open the project in your preferred development environment (e.g., Code Composer Studio).
5. Build the project and flash the binary onto the TM4C123 board.
6. Test the stopwatch functionality by interacting with the buttons and observing the LCD display.

## Usage

- Press first button to start the stopwatch.
- Press second button to pause the stopwatch.
- The elapsed time will be displayed on the LCD screen.

## Notes

- Make sure to consult the datasheets of the TM4C123 microcontroller and your LCD module for accurate pin connections and specifications.
- Feel free to modify and expand upon the project to suit your requirements.

