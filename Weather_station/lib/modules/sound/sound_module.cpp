#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sound_module.h"


// BuzzerDriver buzzer(gpio_pin);
SoundModule::SoundModule(uint8_t _gpio_pin) : buzzer(_gpio_pin) {
    sound_module_init();
}

void SoundModule::sound_module_init() {
    buzzer.BuzzerInit();
}

void SoundModule::start_sound_task() {
    xTaskCreatePinnedToCore(SoundModule::taskEntryBridge, "Sound Task", 1024, NULL, 5, NULL, 1);
}

// Sound Task Bridge
void SoundModule::taskEntryBridge(void *param) {
    auto *instance = static_cast<SoundModule*>(param);
    instance->sound_task_logic();
}

void SoundModule::sound_task_logic() {
    while(1) {
        buzzer.BuzzerOff();
        vTaskDelay(200);
        buzzer.BuzzerOn();
        vTaskDelay(200);
    }
}