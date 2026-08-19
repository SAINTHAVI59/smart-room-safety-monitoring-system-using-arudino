# 🚨 Smart Room Safety Monitoring System Using Arduino

An Arduino-based smart safety monitoring system designed to detect multiple indoor hazards including gas leakage, high temperature, and unauthorized physical proximity.

---

## 📌 Project Overview

The Smart Room Safety Monitoring System is an embedded safety solution developed using an Arduino Uno and multiple sensors.

The system continuously monitors:

- 🌡️ Temperature
- 💧 Humidity
- 🛢️ Gas leakage
- 📏 Physical proximity

When a predefined safety threshold is crossed, the system immediately activates visual and audio alerts.

The project was first tested using Tinkercad simulation and subsequently validated through hardware prototyping.

---

## 🎯 Objectives

The main objectives of the project are:

1. To develop a low-cost indoor safety monitoring system.
2. To integrate multiple sensors with an Arduino Uno.
3. To detect hazardous gas conditions.
4. To monitor abnormal temperature conditions.
5. To detect objects entering a defined proximity zone.
6. To provide immediate visual and audio alerts.
7. To validate the system through simulation and hardware testing.

---

## ✨ Features

- Real-time environmental monitoring
- Gas leakage detection
- Temperature monitoring
- Humidity monitoring
- Ultrasonic proximity detection
- LED-based safety indication
- Audio buzzer alerts
- Priority-based hazard detection
- Arduino-based embedded processing
- Tinkercad simulation support
- Low-cost hardware architecture

---

## 🧩 Hardware Components

| Component | Purpose |
|---|---|
| Arduino Uno | Main controller |
| DHT22 | Temperature and humidity monitoring |
| MQ Gas Sensor | Gas leakage monitoring |
| HC-SR04 | Proximity detection |
| Green LED | Safe condition |
| Yellow LED | High temperature warning |
| Red LED | Critical alert |
| Piezo Buzzer | Audio warning |

---

## 🔌 Pin Configuration

| Component | Pin | Arduino Connection |
|---|---|---|
| MQ Gas Sensor | AO | A0 |
| DHT22 | DATA | D2 |
| HC-SR04 | TRIG | D9 |
| HC-SR04 | ECHO | D10 |
| Green LED | Anode | D3 |
| Yellow LED | Anode | D4 |
| Red LED | Anode | D5 |
| Piezo Buzzer | Positive | D6 |

---

## ⚙️ Safety Thresholds

| Parameter | Threshold | Alert |
|---|---:|---|
| Gas | > 450 | Red LED + 1000 Hz |
| Temperature | > 35°C | Yellow LED + 800 Hz |
| Distance | < 15 cm | Red LED + 1200 Hz |
| Normal | Within limits | Green LED |

---

## 🔄 Working Principle

The Arduino continuously reads data from all connected sensors.

The system follows a priority-based decision process:

```text
Start
  ↓
Initialize Sensors
  ↓
Read Gas Sensor
  ↓
Read Temperature & Humidity
  ↓
Measure Distance
  ↓
Check Gas Threshold
  ↓
Check Temperature Threshold
  ↓
Check Distance Threshold
  ↓
Activate Appropriate Alert
  ↓
Display Status
  ↓
Repeat
