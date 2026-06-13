#include "sound_module.h"
#include "../drivers/actuators/buzzer/buzzer_driver.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

sound_module_t sound;

void sound_module_init(uint8_t gpio_pin) {
    sound.gpio_pin = gpio_pin;
    buzzer_driver_init(sound.gpio_pin);

    xTaskCreatePinnedToCore(sound_task, "Sound Task", 1024, NULL, 5, NULL, 1);
}


void sound_task(void *param) {
    while(1) {
        buzzer_sound_off();
        vTaskDelay(200);
        buzzer_sound_on();
        vTaskDelay(200);
    }
}
