# UART State Machine with Tiva C TM4C123

## Introduction

This project involves implementing a state machine using UART communication between two Tiva C TM4C123 microcontrollers. The state machine controls the flow of data transmission and reception between the two microcontrollers.

### First Tiva C
<img src="https://github.com/hanyNaji/ARM_Projects_TivaC/blob/main/StateMachine_UART/data/uartsm1.png" alt="Alt text" title="Tiva C preview">

### Second Tiva C
<img src="https://github.com/hanyNaji/ARM_Projects_TivaC/blob/main/StateMachine_UART/data/uartsm2.png" alt="Alt text" title="Tiva C preview">


## Software Setup
1. Hardware Configuration: Connect the two Tiva C TM4C123 microcontrollers with proper UART communication pins. Refer to the hardware documentation for pin connections.

2. Software Configuration: Set up the necessary software libraries and development tools for the Tiva C microcontrollers. Ensure you have the required libraries for UART communication.

## Usage
1. UART Communication States: The project implements a state machine with three states: UART Off, UART Read-Only, and UART Read-Write. The states control the behavior of UART data transmission and reception.

2. UART Off State: In this state, UART communication is disabled, and all incoming data is ignored. The state transitions to other states when specific conditions are met.

3. UART Read-Only State: In this state, the microcontroller reads incoming data from UART and displays it on a connected terminal (e.g., PC). The state transitions based on specific conditions, such as receiving a specific character ('#').

4. UART Read-Write State: In this state, the microcontroller simultaneously reads incoming data and sends data to UART. It displays incoming data on the terminal and sends data when the user provides input. The state transitions based on specific conditions, such as receiving a newline character ('\n') or a carriage return character ('\r').

5. UART Error State: In case of errors or buffer overflows, the state transitions to the UART Error state.
