# Central Control System MK1: Pale Raven

![Static Badge](https://img.shields.io/badge/status-ongoing-green)


A robust 1:1 communication protocol between controllers using GPIO pins. While the example here uses an **ESP32** and an **Arduino Uno**, this protocol can be adapted to any microcontroller pair. Communication relies on the flow of current and voltage differences—essentially a high/low signaling system. The only significant latency is introduced by the webserver and the ESP32 interface.

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
| GPIO 17   | D2              | Data Out         |
| GPIO 16   | D3              | Data In          |
| GND       | GND             | Common Ground    |
| 3V3       | 5V (via Reg.)   | Power (if needed)|

> not yet updated

---

## Schematic & Images

- **Schematic Diagram:**  
    ![Schematic](schematic.drawio.svg)

- **Hardware Setup:**  
    ![Hardware](docs/hardware.jpg)


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
