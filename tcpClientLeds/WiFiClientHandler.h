#ifndef WIFICLIENTHANDLER_H
#define WIFICLIENTHANDLER_H

#include <WiFi.h>

class WiFiClientHandler {
private:
  const char * ssid;
  const char * password;
  const char * serverAddress;
  int serverPort;
  WiFiClient client;

public:
  WiFiClientHandler(const char * ssid, const char * password, const char * serverAddress, int serverPort) 
    : ssid(ssid), password(password), serverAddress(serverAddress), serverPort(serverPort) {}

  bool connectWiFi() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println(".");
    }
    Serial.println("WiFi connection established");
    return true;
  }

  bool connectServer() {
    if (client.connect(serverAddress, serverPort)) {
      Serial.println("Successful connection to server");
      return true;
    } else {
      Serial.println("Connection failed");
      return false;
    }
  }

  String fetchData() {
    client.print("GET");
    delay(100);
    String response = client.readString();
    client.stop();
    return response;
  }
};

#endif
