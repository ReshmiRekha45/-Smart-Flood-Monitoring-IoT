# Smart Flood & Urban Drainage Monitoring System (IoT)

An IoT-based real-time waterlogging and flood alert prototype built using **ESP32** and **Ultrasonic Sensors** to prevent urban flooding.

## Live Simulation
- **Run Interactive Simulation:** [Click Here to Test on Wokwi](https://wokwi.com)

## How It Works
- **Water Level Sensing:** Uses an HC-SR04 Ultrasonic Sensor to continuously measure the distance to the water surface inside a drain or reservoir.
- **Automated Alert System:** When the water level crosses the **75% danger threshold**, the ESP32 triggers a **Red LED** visual warning and a **Piezo Buzzer** alarm.
- **IoT Ready:** Connects to Wi-Fi via ESP32, making it scalable for cloud dashboards (ThingSpeak/Blynk) and SMS alerts to municipal authorities.

## Components & Tech Stack
- **Microcontroller:** ESP32 DevKit v1
- **Sensors & Actuators:** HC-SR04 Ultrasonic Sensor, Red LED, Piezo Buzzer
- **Programming:** Embedded C++ (Arduino Framework)
- **Simulation Platform:** Wokwi IoT Simulator
