#include "UltrasonicSensor.h"
#include "WiFiClientHandler.h"
#include "DistanceReporter.h"

#define TRIG_PIN 4
#define ECHO_PIN 2

UltrasonicSensor ultrasonicSensor(TRIG_PIN, ECHO_PIN);
WiFiClientHandler wifiClientHandler("Prueba", "12345678", "192.168.46.72", 8000);
DistanceReporter distanceReporter(ultrasonicSensor, wifiClientHandler);

void setup() {
  Serial.begin(115200);
  Serial.print("Conectando a la red WiFi...");
  if (!wifiClientHandler.connectWiFi()) {
    Serial.println("No se pudo establecer conexión WiFi.");
    while (true);
  }
}

void loop() {
  float distance = distanceReporter.reportDistance();  
  Serial.print("Distancia obtenida: ");
  Serial.println(distance);  
  delay(5000); 
}
