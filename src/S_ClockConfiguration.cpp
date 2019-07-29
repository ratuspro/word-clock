#include <Core.h>
#include <S_ClockConfiguration.h>
#include <S_WordClock.h>
#include <errno.h>
#include <sys/time.h>

S_ClockConfiguration::S_ClockConfiguration() {
    _currentMode = CHANGING_HOURS;
}

void S_ClockConfiguration::Update() {
    std::bitset<NUM_LEDS> bits = S_WordClock::ConvertTimeToLeds(
        _hour, _minute);
    Core::getInstance()->_ledManager->ClearPixels(RgbColor(0, 0, 0));
    Core::getInstance()->_ledManager->SetPixels(bits);
    HandleInput();
}

void S_ClockConfiguration::HandleInput() {
    if (Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::UP)) {
        if (_currentMode == CHANGING_HOURS) {
            _hour = _hour + 1;
            if (_hour >= 12) {
                _hour = 0;
            }
        } else if (_currentMode == CHANGING_MINUTES) {
            _minute = _minute + 5;
            if (_minute >= 60) {
                _minute = 0;
            }
        }
    }
    if (Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::DOWN)) {
        if (_currentMode == CHANGING_HOURS) {
            _hour = _hour - 1;
            if (_hour < 0) {
                _hour = 11;
            }
        } else if (_currentMode == CHANGING_MINUTES) {
            _minute = _minute - 5;
            if (_minute < 0) {
                _minute = 55;
            }
        }
    }

    if (Core::getInstance()->_inputManager->GetKeyDown(
            C_InputManager::CONFIRM)) {
        if (_currentMode == CHANGING_HOURS) {
            _currentMode = CHANGING_MINUTES;
        } else if (_currentMode == CHANGING_MINUTES) {
            SetMachineClock();
            Core::getInstance()->MoveToScreen(std::make_shared<S_WordClock>());
        }
    }
}

void S_ClockConfiguration::SetMachineClock() {
    timeval epoch = {_hour *3600 + _minute * 60,0};
    const timeval *tv = &epoch;
    timezone utc = {0, 0};
    const timezone *tz = &utc;
    Serial.println(epoch.tv_sec);
    settimeofday(tv, tz);
    delay(1000);
}