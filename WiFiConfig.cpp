#include <WiFiConfig.h>

WiFiConfig::WiFiConfig(const char* password) {

    WiFiConfig::password = password;
    WiFiConfig::ssid = "ESPWiFiAP";
    WiFiConfig::server = new AsyncWebServer(80);

}

WiFiConfig::~WiFiConfig() {}

void WiFiConfig::setup() {

    IPAddress local_IP(192, 168, 4, 22);
    IPAddress gateway(192, 168, 4, 9);
    IPAddress subnet(255, 255, 255, 0);

    WiFi.softAPConfig(local_IP, gateway, subnet);
    WiFi.softAP(this->ssid, this->password);
    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);

    this->server->on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", index_html);
    });

    this->server->on("/add", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send_P(200, "text/html", "added");
    });

    this->server->begin();
    Serial.println("Server running");
}