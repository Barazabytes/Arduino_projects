# Weather Station

A PlatformIO-based weather station project for the Adafruit Feather ESP32.
It reads temperature and humidity from a DHT22 sensor and prints values to the serial monitor.

## Features

- Temperature and humidity measurements using a DHT22 sensor
- Serial output for live weather readings
- Modular code structure with separate sensor and actuator drivers
- PlatformIO project configured for `featheresp32`

## Hardware

Recommended hardware:

- Adafruit Feather ESP32
- DHT22 temperature/humidity sensor
- Optional buzzer (driver present but currently disabled in `src/main.cpp`)

## Software Structure

# Weather Station

PlatformIO project for an Adafruit Feather ESP32 that reads temperature and humidity
from a DHT22 sensor and prints measurements to the serial monitor. The codebase is
modular (sensors / actuators / services) so it can be extended with MQTT, HTTP, or
other services.

## Features

- Temperature and humidity readings using a DHT22 sensor
- Serial output (115200 baud) for live readings and debugging
- Small, modular driver layout under `lib/drivers/`

## Target Board & Environment

- Board: Adafruit Feather ESP32
- PlatformIO environment: `featheresp32` (see `platformio.ini`)

## Hardware (recommended)

- Adafruit Feather ESP32 (or compatible ESP32 board)
- DHT22 (AM2302) temperature & humidity sensor
- Optional passive buzzer (driver included in `lib/drivers/actuators/buzzer/`)
- 10 kΩ pull-up resistor for the DHT22 data line (recommended)

### Wiring

- DHT22 VCC -> 3.3V on Feather ESP32
- DHT22 GND -> GND
- DHT22 DATA -> GPIO 4 (controlled by `DHT22_PIN` in `lib/drivers/sensors/dht22/dht22_config.h`)
- Optional buzzer -> any free GPIO (adjust code accordingly)

Note: the project currently defines `DHT22_PIN` as 4 in [lib/drivers/sensors/dht22/dht22_config.h](lib/drivers/sensors/dht22/dht22_config.h#L1-L2).

## Software Structure

- `src/main.cpp` — application entry point and example usage
- `lib/drivers/sensors/dht22/` — DHT22 sensor driver (`dht22_sensor.*`, `dht22_config.h`)
- `lib/drivers/actuators/buzzer/` — buzzer driver
- `lib/services/` — placeholders for `HTTP`, `MQTT`, and `WiFi` service modules
- `platformio.ini` — PlatformIO environment and library dependencies

## Configuration

- Change the DHT pin by editing `lib/drivers/sensors/dht22/dht22_config.h`:

```c
#define DHT22_PIN 4
#define DHTTYPE DHT22
```

## Build & Upload

From the project root, build and upload using PlatformIO:

```bash
platformio run
platformio run --target upload
```

Or use the PlatformIO VS Code extension to build and upload from the GUI.

## Usage

1. Wire the DHT22 (see Wiring section) and connect the Feather ESP32 to your PC.
2. Open a serial monitor at `115200` baud.
3. Reset or power the board. The example in `src/main.cpp` prints lines like:

```
Temperature: 23.40 *C
Humidity: 56.20 %
```

## Enabling the Buzzer

The buzzer driver exists but is commented out in `src/main.cpp`. To enable it:

1. Instantiate `BuzzerDriver buzzer;` in `src/main.cpp` (uncomment if present).
2. Call `buzzer.BuzzerInit();` in `setup()`.
3. Use `buzzer.BuzzerOn()` / `buzzer.BuzzerOff()` where needed.

See `lib/drivers/actuators/buzzer/` for the API and adjust the GPIO pin there.

## Troubleshooting

- If readings are `nan` or `0`, check wiring and the pull-up resistor on the DATA line.
- Ensure `platformio.ini` includes the DHT library dependency (it currently lists `adafruit/DHT sensor library@^1.4.7`).
- Use the serial monitor to view debug output for initialization errors.

## Contributing

- Open issues or pull requests with improvements, sensor support, or service integrations.

## License

This project is provided under the MIT License. Feel free to reuse and adapt the code.

---

If you'd like, I can also add a short example showing how to enable MQTT or a simple JSON output format for the serial logs.
