#include <C_NetworkManager.h>
#include <WiFi.h>
#include <config.h>

void C_NetworkManager::SetupConnection(){
    WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);
}

bool C_NetworkManager::IsConnected() {
    if (WiFi.status() == WL_CONNECTED) {
        return true;
    }
    return false;
}