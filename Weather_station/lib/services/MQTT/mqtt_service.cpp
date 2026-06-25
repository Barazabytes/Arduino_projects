#include <PubSubClient.h>
#include "mqtt_service.h"
#include "mqtt_config.h"
#include <WiFi.h>

WiFiClient espClient;
PubSubClient client(espClient);

void MQTTService::MQTTConnect() {
    client.setServer(MQTT_SERVER, MQTT_PORT);

    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("ESP_DHT22_Client")) {
            Serial.println("connected to broker!");
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" retrying in 5 seconds...");
            delay(5000);
        }
    }
}

void MQTTService::MQTTPublish(const char* topic, const char* payload) {
    // client.setServer(MQTT_SERVER, MQTT_PORT);
    
    if (!client.connected()) {
        MQTTConnect();
    }

    if (client.publish(topic, payload)) {
        Serial.println("Message published successfully");
    } else {
        Serial.println("Message publishing failed");
    }
}