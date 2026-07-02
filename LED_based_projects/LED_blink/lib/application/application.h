#pragma once

#include <stdint.h>

class App {
private:
    uint16_t blink_delay; 
public:
    explicit App();
    void app_run();
};
