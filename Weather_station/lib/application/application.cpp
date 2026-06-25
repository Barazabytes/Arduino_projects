#include <../services/MQTT/mqtt_service.h>
#include <sensors/dht22/dht22_sensor.h>
#include "application_config.h"
#include <WiFi/wifi_service.h>
#include "application.h"

WiFiService wifiService;
DHT22Sensor dht22;
MQTTService mqttService;


void Application::setup() {
    // Initialize WiFi
    wifiService.WiFiBegin();

    // Initialize DHT22 Sensor
    dht22.DHT22Init();

    // Initialize MQTT Service
    mqttService.MQTTConnect();
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

        // Prepare payload
        // char payload[100];
        // snprintf(payload, sizeof(payload), "{\"temperature\": %.2f, \"humidity\": %.2f}", temperature, humidity);
        
        // Construct a JSON payload string
        // Format: {"temperature": 23.50, "humidity": 60.10}
        String payload = "{\"temperature\":" + String(temperature) + ",\"humidity\":" + String(humidity) + "}";
        
        Serial.print("Publishing raw payload: ");
        Serial.println(payload);
        
        // Publish data to MQTT
        mqttService.MQTTPublish(MQTT_TOPIC, payload.c_str());

        // Wait for 5 seconds before next reading
        delay(2000);
    }
}