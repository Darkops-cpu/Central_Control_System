# Central Control System MK1: Pale Raven

![Static Badge](https://img.shields.io/badge/status-completed-orange)


Central Control System MK1: Pale Raven – a 1:1 communication protocol between any two microcontrollers, where the only latency is between your response time and the webserver’s response to the microcontroller. The latter is in milliseconds, but this small detail can be crucial for RTOS systems.

The communication protocol is based on the voltage changes that the GPIO pins generate, and these changes are picked up wherever you want them to be picked up. Now, why not simply implement this over the web? Because electrons travel faster than a microcontroller can send packets through the internet.

In this example, I have taken two commonly found microcontrollers:

ESP32 – communicates with the user via a web interface.

Arduino Uno R3 – controls two DC motors using the L298N motor driver.

Here’s the catch: the ESP32 lacks the power to command two motors directly, while the Arduino can handle two DC motors at the same time but lacks the capability to communicate with the user via a web interface. (the response time was nearly dropped by 35%).

To solve this, a communication protocol is established where the ESP32 acts as the bridge between the Arduino and the user, maintaining smooth 1:1 communication. The only delay comes from the web interface and user interaction.

This system can be implemented in many other ways, with different microcontrollers. Thanks for reading!

---

## Table of Contents

- [Overview](#overview)
- [Pin Connections](#pin-connections)
- [Schematic & Images](#schematic--images)
- [Repository Structure](#repository-structure)
- [License](#license)

---

## Overview

**Pale Raven** enables direct, reliable communication between microcontrollers. The provided example demonstrates an ESP32 and Arduino Uno, but the protocol is hardware-agnostic and can be implemented on other platforms. It is designed for minimal latency, with delays only from the webserver and ESP32 interface.

---

## Pin Connections

| ESP32 Pin | Arduino Uno Pin | Function         |
|-----------|-----------------|------------------|
| GPIO 12   | A0              | forward config   |
| GPIO 13   | A1              | backward config  |
| GPIO 14   | A3              | right config     |
| GPIO 27   | A2              | left config      |


---

## Schematic & Images

- **Schematic Diagram:**  
    ![Schematic](schematic.drawio.svg)

- **Hardware Setup:**  
    ![Hardware](hardware.drawio.svg)


---

## Repository Structure

```
root/
├── Arduino_code/
│   ├── main_arduino.cpp 
│   └── platformio.ini
├── ESP32_code/
│   └── main_esp.cpp
│   └── platformio.ini
├── LICENSE.md
├── README.md
└── schematic.drawio.svg
```

---

## License

MIT License. See [LICENSE](LICENSE) for details.
