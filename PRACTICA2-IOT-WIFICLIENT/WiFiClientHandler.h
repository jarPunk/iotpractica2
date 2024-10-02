#ifndef WIFICLIENTHANDLER_H
#define WIFICLIENTHANDLER_H

#include <WiFi.h>

class WiFiClientHandler {
private:
  const char *ssid;
  const char *password;
  const char *serverAddress;
  int serverPort;
  WiFiClient client;

public:
  WiFiClientHandler(const char *ssid, const char *password, const char *serverAddress, int serverPort) {
    this->ssid = ssid;
    this->password = password;
    this->serverAddress = serverAddress;
    this->serverPort = serverPort;
  }

  bool connectWiFi() {
    WiFi.begin(ssid, password);
    int timeout = 0;
    while (WiFi.status() != WL_CONNECTED && timeout < 30) {
      delay(1000);
      Serial.print(".");
      timeout++;
    }
    if (WiFi.status() == WL_CONNECTED) {
      Serial.println("\nWiFi conectado exitosamente");
      Serial.print("Dirección IP local: ");
      Serial.println(WiFi.localIP());
      return true;
    } else {
      Serial.println("\nFallo al conectar a WiFi");
      return false;
    }
  }

  bool connectServer() {
    if (client.connect(serverAddress, serverPort)) {
      Serial.println("Conexión exitosa con el servidor");
      return true;
    } else {
      Serial.println("Fallo al conectar con el servidor");
      return false;
    }
  }

  void sendData(float distance) {
    if (!client.connected()) {
      connectServer();
    }
    if (client.connected()) {
      String data = "distance=" + String(distance);
      client.print(data);
      Serial.println("Datos enviados: " + data);
    } else {
      Serial.println("Fallo al enviar los datos.");
    }
  }
};

#endif
