#include <Arduino.h>
#include "application.h"

Application app;
void setup() {
  Serial.begin(115200);
  app.application_init();
  app.app_run();
}

void loop() {}