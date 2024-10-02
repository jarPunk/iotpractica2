#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
private:
  int pin;

public:
  Led(int pin) : pin(pin) {}

  void initialize() {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
  }

  void turnOn() {
    digitalWrite(pin, HIGH);
  }

  void turnOff() {
    digitalWrite(pin, LOW);
  }
};

#endif
