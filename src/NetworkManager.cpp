#include <Core.h>
#include <NetworkManager.h>
#include <WiFi.h>
#include <config.h>

NetworkManager::NetworkManager(Core* owner) : Component(owner) {
}

void NetworkManager::Setup() {
    WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}