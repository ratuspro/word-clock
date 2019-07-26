#include <C_LedManager.h>
#include <C_WordMapping.h>
#include <Core.h>
#include <NTPClient.h>
#include <S_ClockConfiguration.h>
#include <S_StartingScreen.h>
#include <S_WordClock.h>
#include <WiFiUdp.h>
#include <sys/time.h>
#include <memory>
#include<WiFi.h>
S_StartingScreen::S_StartingScreen() {
    // Animation
    _numberOfFades = 0;
    _progress = 0;
    _increasing = true;
    // WiFi
    _numAttempts = 0;
    _lastAttempt = clock();
}

void S_StartingScreen::Update() {
    // Handle Animation
    UpdateAnimation();

    if (clock() - _lastAttempt >= NETWORK_TIME_BETWEEN_ATTEMPTS) {
        _lastAttempt = clock();

        if (_numAttempts % NETWORK_NUM_CYCLES == 0) {
            Core::getInstance()->_networkManager->SetupConnection();
        }
        if (!Core::getInstance()->_networkManager->IsConnected()) {
            // Wifi not connected
            if (++_numAttempts >
                NETWORK_NUM_ATTEMPTS_PER_CYCLE * NETWORK_NUM_CYCLES) {
                // Reached the max attempts, move to manual configuration
                Core::getInstance()->MoveToScreen(
                    std::make_shared<S_ClockConfiguration>());
            }
        } else {
            // WiFi is connection, get the time from the NTPClient
            Serial.println("Time not defined.");
            std::unique_ptr<WiFiUDP> udp =
                std::unique_ptr<WiFiUDP>(new WiFiUDP());
            std::unique_ptr<NTPClient> client =
                std::unique_ptr<NTPClient>(new NTPClient(*udp));
            Serial.println("Starting NTPClient...");
            client->begin();
            client->setTimeOffset(TIME_GMT_OFFSET);
            while (!client->update()) {
                client->forceUpdate();
            }
            Serial.println("Retrived time from NTP server");
            Serial.println("Current time: " + client->getFormattedTime());
            int epoch_time = client->getEpochTime();
            timeval epoch = {epoch_time, 0};
            const timeval *tv = &epoch;
            timezone utc = {0, 0};
            const timezone *tz = &utc;
            settimeofday(tv, tz);
            client->end();
            Core::getInstance()->MoveToScreen(std::make_shared<S_WordClock>());
        }
    }
}

void S_StartingScreen::UpdateAnimation() {
    // If no word is defined, select GAIPS
    if (_word.count() == 0) {
        _word = Core::getInstance()->_wordMapping->GetLeds(WordMapping::GAIPS);
        _initialColor = std::make_shared<RgbColor>(0, 0, 0);
        _targetColor = Core::getInstance()->_ledManager->GetColorFromEEPROM();
        Serial.println(_targetColor->B);
    }

    // Manage Animation
    Core::getInstance()->_ledManager->SetPixels(
        _word,
        _targetColor->LinearBlend(*_initialColor, *_targetColor, _progress));

    if (_increasing) {
        _progress += 0.01;
        if (_progress > 1) {
            _progress = 1;
            _increasing = false;
        }
    } else {
        _progress -= 0.01;
        if (_progress < 0) {
            _progress = 0;
            _increasing = true;
            _numberOfFades++;
        }
    }
}