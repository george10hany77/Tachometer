//
// Created by George on 7/28/2024.
//

#include "Tachometer.h"

Tachometer *Tachometer::instance = nullptr;

Tachometer::Tachometer() {
    instance = this;
}

Tachometer::Tachometer(uint16_t pin) {
    instance = this;
    this->sensorPin = pin;
}

bool Tachometer::init() {
    instance = this;
    if (!isValidInterruptPin(sensorPin))
        return false;
    pinMode(sensorPin, INPUT);
    // I made it change because while experimenting it gave the best results
    attachInterrupt(digitalPinToInterrupt(sensorPin), &action, CHANGE);
    instance->timer1 = micros();
    return true;
}

double Tachometer::getRPM() {
    return rpm;
}

bool Tachometer::isValidInterruptPin(uint16_t pin) {
    return digitalPinToInterrupt(pin) != NOT_AN_INTERRUPT;
}

void Tachometer::setSensorPin(uint16_t pin) {
    this->sensorPin = pin;
}

void Tachometer::action() {
    if (instance != nullptr) {
        unsigned long currentTime = millis();
        if (currentTime - instance->lastDebounceTime > instance->debounceDelay) {
            instance->currRevs++;
            instance->lastDebounceTime = currentTime;

            if (instance->currRevs == REVS) {
                unsigned long timeOfAllRevs = micros() - instance->timer1;

                if (timeOfAllRevs > 0) { // Avoid division by zero
                    // the division by 2.0 is essential because of sensor issues "Bouncing"
                    double timePerRev = timeOfAllRevs / 1000000.0 / (REVS / 2.0);
                    instance->rpm = (1.0 / timePerRev) * 60.0;
                } else {
                    instance->rpm = 0;
                }

                instance->currRevs = 0;
                instance->timer1 = micros();
            }
        }
    }
}

uint8_t Tachometer::getCurrentRevs() {
    return currRevs;
}

uint16_t Tachometer::getSensorPin() {
    return sensorPin;
}

