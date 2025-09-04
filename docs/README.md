# Project Documentation: IoT Temperature and Humidity Monitor

This document provides a comprehensive guide to setting up and running the IoT Temperature and Humidity Monitor.

## 1. Hardware Requirements

- **Microcontroller**: ESP8266 (NodeMCU or Wemos D1 Mini recommended).
- **Sensor**: DHT11 Temperature and Humidity Sensor.
- **Jumper Wires**: 3 male-to-female or male-to-male jumper wires.
- **Power**: A micro-USB cable and a power source (PC or wall adapter).

## 2. Software & Platform Setup

### A. Arduino IDE
1.  **Install the IDE**: Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2.  **Add ESP8266 Board Support**:
    - Go to `File > Preferences`.
    - In "Additional Boards Manager URLs", add: `http://arduino.esp8266.com/stable/package_esp8266com_index.json`
    - Go to `Tools > Board > Boards Manager`, search for `esp8266`, and install the package.
3.  **Install Libraries**:
    - Go to `Sketch > Include Library > Manage Libraries...`
    - Search for and install the following libraries:
        - `Blynk` by Volodymyr Shymanskyy
        - `DHT sensor library` by Adafruit
        - `Adafruit Unified Sensor` by Adafruit

### B. Blynk Application
1.  **Install Blynk**: Get the Blynk app from the Google Play Store or Apple App Store.
2.  **Create an Account**: Sign up for a new account.
3.  **Create a New Project**:
    - Tap "New Project".
    - Give your project a name (e.g., "Home Monitor").
    - Set **Device** to `ESP8266`.
    - An **Auth Token** will be sent to your email. You will need this for the code.
4.  **Add Widgets**:
    - Tap the (+) icon to open the widget box.
    - Add two **Gauge** widgets.
    - Configure the first Gauge for Temperature:
        - **Name**: Temperature
        - **PIN**: Virtual `V5`
        - **Range**: 0 to 50 (°C)
    - Configure the second Gauge for Humidity:
        - **Name**: Humidity
        - **PIN**: Virtual `V6`
        - **Range**: 0 to 100 (%)

## 3. Wiring Diagram

Connect the components as described below. The DHT11 sensor has three pins: VCC (power), DATA (signal), and GND (ground).

| DHT11 Sensor Pin | ESP8266 (NodeMCU) Pin | Description      |
|------------------|-----------------------|------------------|
| **VCC (or +)**   | `3V3`                 | 3.3V Power       |
| **DATA (or OUT)**| `D2`                  | Data Signal      |
| **GND (or -)**   | `GND`                 | Ground           |

*(You can add an image of the wiring diagram in the `docs/images/` folder and link it here)*

## 4. Code Configuration & Upload

1.  Open the `Temperature_Humidity_Monitor.ino` sketch in the Arduino IDE.
2.  Update the following lines with your credentials:
    ```cpp
    char auth[] = "YOUR_BLYNK_AUTH_TOKEN"; // Paste the token from your email
    char ssid[] = "YOUR_WIFI_SSID";       // Your Wi-Fi network name
    char pass[] = "YOUR_WIFI_PASSWORD";   // Your Wi-Fi password
    ```
3.  Select your board (`NodeMCU 1.0`) and the correct COM port under the `Tools` menu.
4.  Click the **Upload** button.

## 5. Running the Project

1.  After the upload is complete, open the **Serial Monitor** in the Arduino IDE (set baud rate to 9600) to see debug messages.
2.  In the Blynk app, press the **Play** button (a triangle icon) in the top right corner.
3.  The gauges should now display live data from your sensor!