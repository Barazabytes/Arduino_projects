#include <Arduino.h>
#include "application.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Application app;
  app.application_init();
  app.app_run();
}

void loop() {}
