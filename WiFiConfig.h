#ifndef WiFiConfig_H
#define WiFiConfig_H

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Hash.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <WebTemplates.h>

class WiFiConfig {

    public:
        WiFiConfig(const char* password);
        ~WiFiConfig();

        void setup();

    private:
        const char* password;
        const char* ssid;
        AsyncWebServer* server;
};

#endif