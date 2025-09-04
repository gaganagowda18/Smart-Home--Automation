# IoT-Powered Real-Time Temperature & Humidity Monitor

![Project Banner](https://user-images.githubusercontent.com/26179770/147238274-02621683-0571-4752-9576-65563a365451.png) <!-- You can create a simple banner using Canva or another tool -->

<div align="center">

[![Made with C++](https://img.shields.io/badge/Made%20with-C%2B%2B-00599C.svg?style=for-the-badge&logo=cplusplus)](https://isocpp.org/)
[![Platform - Arduino](https://img.shields.io/badge/Platform-Arduino-00979D.svg?style=for-the-badge&logo=arduino)](https://www.arduino.cc/)
[![IoT Platform - Blynk](https://img.shields.io/badge/IoT%20Platform-Blynk-2CD97B.svg?style=for-the-badge&logo=blynk)](https://blynk.io/)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](https://opensource.org/licenses/MIT)

</div>

A foundational IoT project that captures real-time temperature and humidity data using an ESP8266 and a DHT11 sensor, and visualizes it remotely on a sleek mobile dashboard built with the Blynk IoT platform. This project serves as an excellent entry point into smart home automation and remote environmental monitoring.

---

## 🚀 Live Demo Showcase

This GIF demonstrates the system in action. The ESP8266 wirelessly transmits sensor data, which is then displayed in real-time on the Blynk mobile application from anywhere in the world.

<p align="center">
  <img src="assets/live-demo.gif" alt="Live Demo GIF" width="300"/>
</p>
<!-- To create this: Record your phone screen while the Blynk app is running and convert the video to a GIF using a site like ezgif.com. Place the GIF in an 'assets' folder. -->


## ✨ Key Features

- **Real-Time Data Monitoring:** Instantly view live temperature (°C) and humidity (%) readings.
- **Remote Accessibility:** Access the dashboard from any location with an internet connection via the Blynk app.
- **Low-Power Consumption:** Utilizes the efficient ESP8266 microcontroller, suitable for long-term operation.
- **Simple & Scalable:** The modular design allows for easy expansion with additional sensors or actuators (e.g., fans, heaters, alerts).
- **User-Friendly Interface:** Clean and intuitive data visualization using gauges on a mobile dashboard.

---

## 🛠️ Technologies & Tools Used

This project integrates a variety of hardware and software components to achieve its functionality.

| Category          | Technology / Tool                                                                       |
| ----------------- | --------------------------------------------------------------------------------------- |
| **Hardware**      | <li>ESP8266 (NodeMCU)</li><li>DHT11 Temperature & Humidity Sensor</li><li>Jumper Wires & Breadboard</li> |
| **Software**      | <li>C++ (Arduino Framework)</li><li>Visual Studio Code with PlatformIO (or Arduino IDE)</li> |
| **IoT Platform**  | <li>Blynk IoT Platform (Mobile App & Cloud Server)</li>                                |
| **Libraries**     | <li>Blynk Library</li><li>Adafruit DHT Sensor Library</li><li>Adafruit Unified Sensor</li> |

---

## 🔧 System Architecture & Wiring

The system architecture is straightforward. The DHT11 sensor measures the ambient conditions and sends this data to the ESP8266 microcontroller. The ESP8266 then connects to your local Wi-Fi to push the data to the Blynk Cloud, which in turn updates the dashboard on your smartphone.

<p align="center">
  <img src="assets/wiring-diagram.png" alt="Wiring Diagram" width="500"/>
</p>
<!-- Create a simple wiring diagram using a tool like Fritzing.org and save it in your 'assets' folder. -->

| DHT11 Sensor Pin | ESP8266 (NodeMCU) Pin |
| ---------------- | --------------------- |
| **VCC (+)**      | `3V3`                 |
| **DATA (OUT)**   | `D2` (GPIO4)          |
| **GND (-)**      | `GND`                 |

---

## ⚙️ Getting Started: A Step-by-Step Guide

To replicate this project, follow the setup guide below.

### Prerequisites

- [Arduino IDE](https://www.arduino.cc/en/software) or [VS Code with PlatformIO](https://platformio.org/) installed.
- A Blynk account.
- All required hardware components listed above.

### Step 1: Configure the Blynk Mobile App

1.  **Download Blynk App** for [iOS](https://apps.apple.com/us/app/blynk-iot/id1559317869) or [Android](https://play.google.com/store/apps/details?id=io.blynk.app).
2.  **Create a New Project**:
    - Choose **ESP8266** as the hardware.
    - An **Auth Token** will be emailed to you. **Save this token!**
3.  **Add Widgets**:
    - Add two **Gauge** widgets to the dashboard.
    - **Gauge 1 (Temperature)**: Set PIN to **Virtual Pin V5**, range `0-50`.
    - **Gauge 2 (Humidity)**: Set PIN to **Virtual Pin V6**, range `0-100`.

### Step 2: Set Up & Upload the Code

1.  **Clone the Repository**:
    ```bash
    git clone https://github.com/YourUsername/IoT_Temperature_Humidity_Monitor_Project.git
    cd IoT_Temperature_Humidity_Monitor_Project
    ```
2.  **Install Libraries**: Open the Arduino IDE and install `Blynk`, `DHT sensor library`, and `Adafruit Unified Sensor` from the Library Manager.

3.  **Configure Credentials**:
    - Open the main `.ino` sketch file.
    - Update the following placeholders with your credentials:
      ```cpp
      char auth[] = "YOUR_BLYNK_AUTH_TOKEN"; // From your email
      char ssid[] = "YOUR_WIFI_SSID";
      char pass[] = "YOUR_WIFI_PASSWORD";
      ```
4.  **Upload the Sketch**:
    - Connect your ESP8266 to your computer.
    - Select the correct board (`NodeMCU 1.0`) and COM port.
    - Click **Upload**.

### Step 3: Launch!

Once the code is uploaded, open the Blynk App, press the "Play" button (▶), and watch your real-time data appear on the dashboard.

---

## 📈 Future Improvements

This project has great potential for expansion. Here are a few ideas:
- **Data Logging:** Store historical data in a database (like Google Sheets or InfluxDB) for trend analysis.
- **Automated Alerts:** Send push notifications or emails if the temperature or humidity exceeds predefined thresholds.
- **Actuator Control:** Add a relay to control a fan or a small heater, turning this into a fully automated climate control system.
- **Web Dashboard:** Create a web-based dashboard using Node-RED or Grafana for a more comprehensive view.

---

## 📄 License

This project is open-source and licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute the code.

---

*Made with ❤️ by [Gagana Gowda]*
