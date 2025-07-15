# Central Control System MK1: Pale Raven

A robust 1:1 communication protocol between an **ESP32** and an **Arduino Uno**, utilizing GPIO pins for direct hardware interaction. This project aims to provide reliable, low-latency control, with the only significant delay arising from the ESP32's connection to the webserver.

---

## Features

- Direct GPIO-based communication between ESP32 and Arduino Uno
- Minimal communication delay (limited to ESP32 ↔ webserver latency)
- Easily configurable pin assignments
- Simple and maintainable codebase

---

## Repository Structure

```
/
├── main_esp32.ino      # ESP32 main firmware
├── main_arduino.ino    # Arduino Uno main firmware
├── config.ini          # Configuration file
├── settings.ini        # Additional settings
├── sketch.png          # System schematic
└── README.md           # Project documentation
```

---

## GPIO Pin Assignments

| Function         | ESP32 Pin | Arduino Uno Pin |
|------------------|-----------|-----------------|
| Data Line        |           |                 |
| Clock Line       |           |                 |
| Handshake Line   |           |                 |
| Status Indicator |           |                 |

*Please update the pin numbers as per your hardware setup.*

---

## System Overview

![System Schematic](sketch.png)

*Add your system schematic above.*

---

## Example Communication Flow

1. ESP32 sends a signal via GPIO.
2. Arduino Uno receives and processes the signal.
3. Response is sent back through designated pins.
4. Webserver interaction introduces the only notable latency.

---

## Images

<!-- Add your images below -->

![Image 1: Hardware Setup](path/to/image1.png)

![Image 2: Communication Flow](path/to/image2.png)

---

## License

This project is licensed under the MIT License.

---

## Contact

For questions or contributions, please open an issue or submit a pull request.
