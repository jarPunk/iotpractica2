#include <Arduino.h>
#include "WiFiClientHandler.h"
#include "Led.h"

WiFiClientHandler wifiHandler("Prueba", "12345678", "192.168.234.72", 8000);

const int LED_GREEN = 33;
const int LED_YELLOW = 32;
const int LED_RED = 5;

Led greenLED(LED_GREEN);
Led yellowLED(LED_YELLOW);
Led redLED(LED_RED);

void updateLedsState(const String &value) {
  if (value == "RED") {
    greenLED.turnOff();
    redLED.turnOn();
    yellowLED.turnOff();
  } else if (value == "YELLOW") {
    greenLED.turnOff();
    redLED.turnOff();
    yellowLED.turnOn();
  } else if (value == "GREEN") {
    greenLED.turnOn();
    redLED.turnOff();
    yellowLED.turnOff();
  }
}

void setup() {
  Serial.begin(115200);

  greenLED.initialize();
  yellowLED.initialize();
  redLED.initialize();

  wifiHandler.connectWiFi();
}

void loop() {
  if (wifiHandler.connectServer()) {
    String value = wifiHandler.fetchData();
    
    Serial.print("Received value: ");
    Serial.println(value);

    updateLedsState(value);
  }
  delay(2000);
}
