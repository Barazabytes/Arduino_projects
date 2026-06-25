#include <../services/MQTT/mqtt_service.h>
#include <sensors/dht22/dht22_sensor.h>
#include "application_config.h"
#include <WiFi/wifi_service.h>
#include "application.h"
#include <actuators/buzzer/buzzer_driver.h>

WiFiService wifiService;
DHT22Sensor dht22;
MQTTService mqttService;
BuzzerDriver buzzer;


void Application::setup() {
    // Initialize WiFi
    wifiService.WiFiBegin();

    // Initialize DHT22 Sensor
    dht22.DHT22Init();

    // Initialize MQTT Service
    mqttService.MQTTConnect();

    // Initialize Buzzer
    buzzer.BuzzerInit();
}

void Application::run() {
    // Main application loop
    while (1) {
        // Read sensor data
        float humidity = dht22.ReadHumidity();
        float temperature = dht22.ReadTemperature();

        // Check if any reads failed
        if (isnan(humidity) || isnan(temperature)) {
            Serial.println("Failed to read from DHT sensor!");
            continue;
        }
        
        // Construct a JSON payload string
        // Format: {"temperature": 23.50, "humidity": 60.10}
        String payload = "{\"temperature\":" + String(temperature) + ",\"humidity\":" + String(humidity) + "}";
        
        Serial.print("Publishing raw payload: ");
        Serial.println(payload);
        
        // Publish data to MQTT
        mqttService.MQTTPublish(MQTT_TOPIC, payload.c_str());

        // Make a beep sound if temperature exceeds threshold
        if (temperature > TEMPERATURE_THRESHOLD) {
            for (int i = 0; i < MAX_BEEPS; i++) {
                buzzer.BuzzerOn();
                delay(200);
                buzzer.BuzzerOff();
                delay(200);
            }
        }

        // Wait for 2 seconds before next reading
        delay(2000);
    }
}