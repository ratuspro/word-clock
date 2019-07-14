#include <Core.h>
#include <C_NetworkManager.h>
#include <WiFi.h>
#include <config.h>

NetworkManager::NetworkManager() : Component() {
}

void NetworkManager::Setup() {
    Serial.println("Started connecting to WiFi");
    WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);
    
    for(uint8_t attempt = 0; attempt < NETWORK_NUM_ATTEMPTS; attempt++){
        Serial.print("Attempt #");
        Serial.println(attempt);
        if(WiFi.status() == WL_CONNECTED){
            Serial.print("Connected to ");
            Serial.println(NETWORK_SSID);
            break;
        }
        delay(NETWORK_TIME_BETWEEN_ATTEMPTS);
    }

    Serial.println(WiFi.localIP());
    if(WiFi.status() != WL_CONNECTED){
        Serial.print("Failed to connect to ");
        Serial.print(NETWORK_SSID);
        Serial.print(" using password ");
        Serial.println(NETWORK_PASSWORD);
    }
}