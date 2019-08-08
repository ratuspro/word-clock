#include <Core.h>
#include <S_ClockConfiguration.h>
#include <S_WordClock.h>
#include <errno.h>
#include <sys/time.h>

std::vector<LedCoord> _watchFrame = {
    {3, 1},{4, 1},{5, 1},{6, 1},{7, 1},
    {2, 2},{3, 2},{7, 2},{8, 2},
    {2, 3},{8, 3},
    {2, 4},{8, 4},
    {2, 5},{8, 5},
    {2, 6},{8, 6},
    {2, 7},{3, 7},{7, 7},{8, 7},
    {3, 8},{4, 8},{5, 8},{6, 8},{7, 8}};

std::vector<LedCoord> _watchHands = {{5, 2},{5, 3},{5, 4},{6, 4}};

std::vector<LedCoord> _watchWheels = {{9, 4},{9, 5}};

S_ClockConfiguration::S_ClockConfiguration(bool initialConfig, Screen_Menu::MENU_STAGE stage = Screen_Menu::ICON) : Screen_Menu(stage) {
    _currentMode = CHANGING_HOURS;
    _ticksToChange = 60;
    _filled = true;
    _initialConfig = initialConfig;
    struct tm now;
    getLocalTime(&now, 0);
    _hour = now.tm_hour;
    _minute = now.tm_min;
}

void S_ClockConfiguration::Update() {
    if (CurrentStage == MENU_STAGE::ICON) {
        DrawFrame(RgbColor(255,255,255));
        DrawHands(Core::getInstance()->_eepromManager->GetForegroundColor());
        DrawWheel(Core::getInstance()->_eepromManager->GetForegroundColor());
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
            if(_initialConfig){
                _currentMode = CHANGING_HOURS;
                Core::getInstance()->MoveToScreen(std::make_shared<S_WordClock>());
            }else{
                _currentMode = CHANGING_HOURS;
                ExitScreen();
            }
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

void S_ClockConfiguration::DrawFrame(RgbColor color){
    Core::getInstance()->_ledManager->SetPixels(_watchFrame,color);
}

void S_ClockConfiguration::DrawHands(RgbColor color){
    Core::getInstance()->_ledManager->SetPixels(_watchHands,color);
}

void S_ClockConfiguration::DrawWheel(RgbColor color){
    Core::getInstance()->_ledManager->SetPixels(_watchWheels,color);
}