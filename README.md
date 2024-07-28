# Tachometer Library for Arduino

## Disclaimer

You can only create one instance

## Overview

The Tachometer library allows you to measure the rotational speed (RPM) using a tachometer sensor with an Arduino. It provides an easy interface to initialize the sensor, handle interrupts, and calculate RPM based on sensor pulses.

## Features

- **Simple Initialization**: Easy setup of the tachometer sensor pin.
- **RPM Calculation**: Accurate calculation of RPM with debounce handling.
- **Customizable Revolutions**: Configure the number of revolutions for averaging RPM calculations.

## Installation

1. **Manual Installation**:
   - Download the `Tachometer` library files.
   - Place the `Tachometer` folder into your Arduino libraries directory, typically found at `Documents/Arduino/libraries`.

2. **Using the Arduino IDE**:
   - Go to **Sketch > Include Library > Add .ZIP Library...**
   - Select the `.zip` file containing the `Tachometer` library.

## Disclaimer

You can create only one instance

## Usage

### Basic Example

Here’s a simple example to get you started with the Tachometer library:

```cpp
#include <Tachometer.h>

const uint16_t SENSOR_PIN = 2; // Replace with your sensor pin

Tachometer tachometer(SENSOR_PIN);

void setup() {
    Serial.begin(9600);
    if (!tachometer.init()) {
        Serial.println("Tachometer initialization failed!");
    }
}

void loop() {
    double rpm = tachometer.getRPM();
    Serial.print("RPM: ");
    Serial.println(rpm);
    delay(1000); // Update every second
}
