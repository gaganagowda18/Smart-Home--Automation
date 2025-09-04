/*
 * ===============================================================
 * Project: IoT Temperature and Humidity Monitor
 * Author: Your Name
 * Date: 2025-09-04
 * Description: This sketch reads temperature and humidity data
 *              from a DHT11 sensor using an ESP8266 and sends
 *              it to the Blynk IoT platform for remote monitoring.
 *
 * Hardware:
 *  - ESP8266 (NodeMCU or similar)
 *  - DHT11 Temperature and Humidity Sensor
 *
 * Wiring:
 *  - ESP8266 3V3 -> DHT11 VCC (+)
 *  - ESP8266 GND -> DHT11 GND (-)
 *  - ESP8266 D2  -> DHT11 DATA (OUT)
 * ===============================================================
*/

// Define this to print debug messages to the Serial Monitor
#define BLYNK_PRINT Serial

// Required Libraries
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

// --- UPDATE THESE CONFIGURATION VALUES ---

// Authentication Token for your Blynk Project
// (Get this from the Blynk App)
char auth[] = "YOUR_BLYNK_AUTH_TOKEN";

// Your Wi-Fi network credentials
char ssid[] = "YOUR_WIFI_SSID";
char pass[] = "YOUR_WIFI_PASSWORD";

// --- SENSOR CONFIGURATION ---

// Define the GPIO pin the DHT11's data pin is connected to
// For NodeMCU, D2 corresponds to GPIO4
#define DHTPIN 4

// Define the type of DHT sensor being used (DHT11, DHT22, etc.)
#define DHTTYPE DHT11

// --- GLOBAL OBJECTS ---

// Initialize the DHT sensor object
DHT dht(DHTPIN, DHTTYPE);

// Create a Blynk timer object to schedule tasks
BlynkTimer timer;

// --- FUNCTIONS ---

/**
 * @brief Reads data from the DHT sensor and sends it to Blynk virtual pins.
 * This function is scheduled to run periodically by the timer.
 */
void sendSensorData()
{
  // Read humidity and temperature from the sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Default is Celsius

  // Check if any reads failed and exit early to avoid sending bad data.
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Error: Failed to read from DHT sensor!");
    return;
  }

  // For debugging: Print the values to the Serial Monitor
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%  |  Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Send the data to the Blynk app
  Blynk.virtualWrite(V5, temperature); // Send temperature to Virtual Pin V5
  Blynk.virtualWrite(V6, humidity);    // Send humidity to Virtual Pin V6
}


// --- MAIN PROGRAM ---

/**
 * @brief Setup function, runs once at startup.
 */
void setup()
{
  // Start the serial monitor for debugging purposes (baud rate 9600)
  Serial.begin(9600);
  Serial.println("\nStarting IoT Temperature and Humidity Monitor...");

  // Initialize the DHT sensor
  dht.begin();

  // Connect to your Wi-Fi network and the Blynk server
  Blynk.begin(auth, ssid, pass);

  // Set up a timer to call the sendSensorData() function every 2 seconds (2000 milliseconds)
  timer.setInterval(2000L, sendSensorData);
}

/**
 * @brief Main loop function, runs repeatedly.
 */
void loop()
{
  // This command runs the Blynk service (handles connection and data)
  Blynk.run();

  // This command runs the timer service
  timer.run();
}