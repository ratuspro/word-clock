#include <Core.h>
#include <S_NTPClient.h>
#include <S_NetworkingConnectionScreen.h>
#include <WiFi.h>

void S_NetworkingConnectionScreen::Update() {
    if (Screen::_currentState == Screen::State::RUNNING) {
        if (_attempts == 1 || clock() - _lastAttempt >= NETWORK_TIME_BETWEEN_ATTEMPTS) {
            Core::getInstance()->_ledManager->ClearPixels(RgbColor(0,0,0));
            Core::getInstance()->_ledManager->SetPixels(Core::getInstance()->_wordMapping->GetLeds(_attempts),RgbColor(0,0,255));
            
            if (_attempts % 3 == 0) {
                Serial.println("Connecting to WiFi");
                WiFi.begin(NETWORK_SSID, NETWORK_PASSWORD);
            }

            _lastAttempt = clock();
            Serial.print("Attempt #");
            Serial.println(_attempts);
            if (!TryConnection()) {
                if (++_attempts > NETWORK_NUM_ATTEMPTS) {
                    Serial.print("Failed to connect to ");
                    Serial.println(NETWORK_SSID);
                    Core::getInstance()->MoveToScreen(
                        std::make_shared<S_NetworkingConnectionScreen>());
                }
            } else {
                Serial.print("Connected to ");
                Serial.println(NETWORK_SSID);
                Serial.print("Current IP: ");
                Serial.println(WiFi.localIP());
                Core::getInstance()->MoveToScreen(
                    std::make_shared<S_NTPClient>());
            }
        }
    }
}

bool S_NetworkingConnectionScreen::TryConnection() {
    if (WiFi.status() == WL_CONNECTED) {
        return true;
    }
    return false;
}