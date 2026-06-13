#include <Arduino.h>

extern "C" { 
#include <sound/sound_module.h>
}


void setup() {
  // put your setup code here, to run once:
  sound_module_init(5);
}

void loop() {
  // put your main code here, to run repeatedly:

}
