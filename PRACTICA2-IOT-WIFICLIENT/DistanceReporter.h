#ifndef DISTANCEREPORTER_H
#define DISTANCEREPORTER_H

#include "UltrasonicSensor.h"
#include "WiFiClientHandler.h"

class DistanceReporter {
private:
  UltrasonicSensor &sensor;
  WiFiClientHandler &wifiClient;

public:
  DistanceReporter(UltrasonicSensor &sensor, WiFiClientHandler &wifiClient) : sensor(sensor), wifiClient(wifiClient) {}

  float reportDistance() {
    float distance = sensor.measureDistance();
    Serial.print("Distancia medida: ");
    Serial.println(distance);
    wifiClient.sendData(distance);
    return distance;  
  }
};

#endif
