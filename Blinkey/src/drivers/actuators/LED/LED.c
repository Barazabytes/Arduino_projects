#include "../../../app_hal/hal_gpio/hal_gpio.h"


void LED_init(uint8_t pin, pin_mode_t mode) {
    hal_gpio_init(pin, mode);
}

void LED_on(uint8_t pin) {
    hal_gpio_write(pin, true);
}
void LED_off(uint8_t pin) {
    hal_gpio_write(pin, false);
}