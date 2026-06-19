#include <Arduino.h>
 #include "esp_log.h"

#include <sound/sound_module.h>
// #include <weather/weather_module.h>

void setup() {

  Serial.begin(9600);
  SoundModule sound_module(2);
  sound_module.start_sound_task();

  // weather_module_init(4);
}

void loop() {
  // put your main code here, to run repeatedly:

}
