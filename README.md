# Smart Robo Car with Object Detection and Remote Control

## 🚗 Project Overview
This project is an advanced Arduino-based robo car that can be controlled remotely using Bluetooth and can also operate autonomously using object detection. The car detects obstacles using an ultrasonic sensor and intelligently avoids them.

The robot supports two modes:
- **Manual Mode** – Controlled using a remote (Bluetooth)
- **Auto Mode** – Object detection and obstacle avoidance

---

## 🎯 Features
- Bluetooth remote control
- Automatic obstacle detection
- Intelligent direction decision
- Servo-based object scanning
- Dual operation modes
- Hackathon & competition ready

---

## 🧠 Technologies Used
- Arduino UNO
- C / C++ (Arduino IDE)
- Ultrasonic Sensor (HC-SR04)
- Bluetooth Communication
- Motor Driver (L298N)

---

## 🧩 Components Required
- Arduino UNO
- L298N Motor Driver
- DC Motors & Wheels
- HC-SR04 Ultrasonic Sensor
- Servo Motor (SG90)
- HC-05 Bluetooth Module
- Robot Chassis
- Battery (7.4V–12V)
- Jumper Wires

---

## 🔌 Pin Configuration

### Motor Driver (L298N)
| Pin | Arduino |
|----|---------|
| IN1 | 8 |
| IN2 | 9 |
| IN3 | 10 |
| IN4 | 11 |
| ENA | 5 |
| ENB | 6 |

### Ultrasonic Sensor
| Pin | Arduino |
|----|---------|
| TRIG | 2 |
| ECHO | 3 |

### Servo Motor
| Pin | Arduino |
|----|---------|
| Signal | 4 |

### Bluetooth Module
| Pin | Arduino |
|----|---------|
| TX | RX |
| RX | TX |
| VCC | 5V |
| GND | GND |

---

## 📱 Bluetooth Commands
| Command | Action |
|--------|-------|
| F | Forward |
| B | Backward |
| L | Left |
| R | Right |
| S | Stop |
| A | Auto Mode |
| M | Manual Mode |

---

## ⚙️ Working Principle
- The Bluetooth remote sends commands to the robo car
- Arduino processes commands and controls motors
- Ultrasonic sensor detects obstacles
- Servo scans surroundings
- Car decides direction intelligently

---

## 🚀 Future Enhancements
- ESP32 Camera integration
- Voice control
- GPS tracking
- OLED display
- AI-based image recognition

---

## 🏁 Conclusion
This project demonstrates a smart robotic system combining remote control and autonomous intelligence. It is suitable for students, hackathons, and robotics competitions.

---

## 👨‍💻 Author
Achuthan Rameshkumar
# rc-car
