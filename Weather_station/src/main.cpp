#include <Arduino.h>
#include <actuators/buzzer/buzzer_driver.h>
#include <sensors/dht22/dht22_sensor.h>
// #include <weather/weather_module.h>

// BuzzerDriver buzzer;
DHT22Sensor dht22;

void setup() {
  // buzzer.BuzzerInit();
  dht22.DHT22Init();
  Serial.begin(115200);
  // weather_module_init(4);
}

void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dht22.ReadTemperature();
  float humidity = dht22.ReadHumidity();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  delay(2000); // Wait a few seconds between measurements.

}
