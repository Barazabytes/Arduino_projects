#include <Arduino.h>

extern "C" {
    #include "drivers/actuators/LED/LED.h"
}

void setup() {
  // put your setup code here, to run once:
  LED_init(2, PIN_MODE_OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  LED_on(2);
  delay(1000);
  LED_off(2);
  delay(1000);
}