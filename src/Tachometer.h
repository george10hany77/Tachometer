//
// Created by George on 7/28/2024.
//

#ifndef UNTITLED_TACHOMETER_H
#define UNTITLED_TACHOMETER_H

#include <Arduino.h>

class Tachometer{
public:
    Tachometer();
    explicit Tachometer(uint16_t pin);
    bool init();
    double getRPM();
    void setSensorPin(uint16_t pin);
    uint8_t getCurrentRevs();
    uint16_t getSensorPin();

private:
    #define REVS 20
    uint16_t sensorPin;
    volatile uint8_t currRevs = 0;
    volatile unsigned long timer1 = 0;
    volatile double rpm = 0;
    volatile const unsigned long debounceDelay = 1; // milliseconds
    volatile unsigned long lastDebounceTime = 0;
    bool isValidInterruptPin(uint16_t pin);
    static void action();

    static Tachometer* instance; // Static pointer to instance, Default Value : nullptr
};

#endif //UNTITLED_TACHOMETER_H
