# Required Libraries

This project requires three external libraries to be installed in the Arduino IDE. You can install them using the Arduino Library Manager (`Sketch > Include Library > Manage Libraries...`).

1.  **Blynk Library**
    - **Purpose**: Handles all communication between the ESP8266 and the Blynk cloud platform.
    - **Author**: Volodymyr Shymanskyy
    - **GitHub**: [https://github.com/blynkkk/blynk-library](https://github.com/blynkkk/blynk-library)

2.  **DHT sensor library**
    - **Purpose**: Provides the necessary functions to read data from DHT series sensors (DHT11, DHT22, etc.).
    - **Author**: Adafruit
    - **GitHub**: [https://github.com/adafruit/DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library)

3.  **Adafruit Unified Sensor Driver**
    - **Purpose**: This is a dependency for the Adafruit DHT library. It provides a unified sensor abstraction layer.
    - **Author**: Adafruit
    - **GitHub**: [https://github.com/adafruit/Adafruit_Sensor](https://github.com/adafruit/Adafruit_Sensor)

If you prefer to install libraries manually, you can download them as ZIP files from their respective GitHub pages and add them to your Arduino IDE via `Sketch > Include Library > Add .ZIP Library...`.