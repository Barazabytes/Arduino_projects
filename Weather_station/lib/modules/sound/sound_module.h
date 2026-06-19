#pragma once

#include "../../drivers/actuators/buzzer/buzzer_driver.h"
#include <stdint.h>

class SoundModule {
    private:
        uint8_t gpio_pin;
        static void taskEntryBridge(void *param);
        void sound_task_logic();
        BuzzerDriver buzzer;

    public:
    explicit SoundModule(uint8_t _gpio_pin);
        void start_sound_task();
        void sound_module_init();
};