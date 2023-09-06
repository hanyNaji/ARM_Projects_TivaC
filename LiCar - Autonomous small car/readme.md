# Small Autonomous Car with Tiva C TM4C123


## Introduction

The Autonomous Car Control System is a project designed to control a small autonomous car. It utilizes various sensors and motors to make decisions based on sensor inputs. The car's behavior is programmed to respond to temperature, ultrasonic distance, and light intensity readings to navigate autonomously.

<img src="https://github.com/hanyNaji/ARM_Projects_TivaC/blob/main/LiCar%20-%20Autonomous%20small%20car/Documentation/car1.jpeg" alt="Alt text" title="Tiva C preview">


### Hardware Components

- **Temperature Sensor**: Measures the ambient temperature.
- **Ultrasonic Sensor**: Calculates the distance to nearby objects.
- **Light Dependent Resistors (LDRs)**: Used to detect variations in light intensity.
- **LCD Display**: Provides real-time information display.
- **DC Motors**: Makes the car able to move in any diriction.

### Software Setup

To set up the software for this project, follow these steps:

1. **Hardware Configuration**: Connect all the sensors and actuators to your Tiva C TM4C123 microcontroller as per the hardware documentation.

2. **Software Configuration**: Set up the necessary software libraries and development tools for your Tiva C microcontroller. Ensure you have the required libraries for sensor readings and motor control.

### Usage

The main loop of the program continuously reads sensor values and controls the car's behavior based on these readings. Here's a high-level overview of the logic:

- **Temperature Reading**: The project reads the ambient temperature using the temperature sensor.

- **Ultrasonic Distance Measurement**: Ultrasonic sensors are used to measure the distance to nearby objects. If an object is detected within a certain range (e.g., less than 20 cm), the car is programmed to perform a specific action (e.g., turning 180 degrees).

- **Light Intensity Detection**: Light-dependent resistors (LDRs) monitor changes in light intensity. Based on the readings, the car decides whether to turn right or left. If a significant difference in light intensity is detected (e.g., LDRDiff > 200), the car turns right. Conversely, if there is a significant difference in the opposite direction (e.g., LDRDiff < -200), the car turns left. Otherwise, it stops.

- **LCD Display**: Real-time sensor readings, distance measurements, and car actions are displayed on an LCD screen.

### Contributing

Contributions to this project are welcome! If you have ideas for improvements, bug fixes, or additional features, please open an issue or submit a pull request.

### License

This project is open-source and available under the [MIT License](LICENSE).

---

*Note: This README provides an overview of the Autonomous Car Control System project. For detailed setup instructions, code examples, and hardware connections, please refer to the project's documentation and source code.*
