#include <Core.h>
#include <S_ClockConfiguration.h>
#include <S_WordClock.h>
#include <errno.h>
#include <sys/time.h>

S_ClockConfiguration::S_ClockConfiguration(Screen_Menu::MENU_STAGE stage = Screen_Menu::ICON) : Screen_Menu(stage) {
    _currentMode = CHANGING_HOURS;
    _ticksToChange = 60;
    _filled = true;

    struct tm now;
    getLocalTime(&now, 0);
    _hour = now.tm_hour;
    _minute = now.tm_min;
}

void S_ClockConfiguration::Update() {
    if (CurrentStage == MENU_STAGE::ICON) {
        
    } else {
        HandleInput();

        // Clear all pixels
        Core::getInstance()->_ledManager->ClearPixels();

        // Fill entire time
        Core::getInstance()->_ledManager->SetPixels(
            Core::getInstance()->_wordManager->ConvertTimeToPixels(_hour,
                                                                   _minute),
            Core::getInstance()->_eepromManager->GetForegroundColor());

        // Blink relevant component
        if (!_filled) {
            if (_currentMode == CHANGING_MINUTES) {
                Core::getInstance()->_ledManager->SetPixels(
                    Core::getInstance()->_wordManager->ConvertMinutesToPixels(
                        _minute),
                    RgbColor(0, 0, 0));
            } else {
                Core::getInstance()->_ledManager->SetPixels(
                    Core::getInstance()->_wordManager->ConvertHoursToPixels(
                        _hour, _minute > 30),
                    RgbColor(0, 0, 0));
            }
        }

        // Update Timer
        if (--_ticksToChange == 0) {
            ResetTimer(!_filled);
        }
    }
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
        ResetTimer(true);
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
        ResetTimer(true);
    }

    if (Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::CONFIRM)) {
        if (_currentMode == CHANGING_HOURS) {
            _currentMode = CHANGING_MINUTES;
            ResetTimer(true);
        } else if (_currentMode == CHANGING_MINUTES) {
            SetMachineClock();
            Core::getInstance()->MoveToScreen(std::make_shared<S_WordClock>());
        }
    }
}

void S_ClockConfiguration::SetMachineClock() {
    timeval epoch = {_hour * 3600 + _minute * 60, 0};
    const timeval *tv = &epoch;
    timezone utc = {0, 0};
    const timezone *tz = &utc;
    settimeofday(tv, tz);
}

void S_ClockConfiguration::ResetTimer(bool isFilled) {
    if (_filled) {
        _ticksToChange = 40;
    } else {
        _ticksToChange = 60;
    }
    _filled = isFilled;
}