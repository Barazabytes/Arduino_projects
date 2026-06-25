#pragma once

class MQTTService {
public:
    void MQTTConnect();
    void MQTTPublish(const char* topic, const char* payload);
};