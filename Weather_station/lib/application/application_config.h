#pragma once

// MQTT Configuration
#define MQTT_TOPIC "room/sensor/dht22"
#define MQTT_SERVER "10.42.0.28"
#define MQTT_PORT 1883

// WiFi Configuration
#define WIFI_SSID "ByteLink_6G"
#define WIFI_PASSWORD "miminawewemilele"

// DHT22 Sensor Configuration
#define DHTPIN 4
#define DHTTYPE DHT22

// Buzzer Configuration
#define BUZZER_PIN 5
#define TEMPERATURE_THRESHOLD 25.0
#define MAX_BEEPS 5
