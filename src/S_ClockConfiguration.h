#include <Screen_Menu.h>
#include <time.h>
#include <C_LedManager.h>
#include <C_InputManager.h>

#ifndef S_CLOCKCONFIGURATION_H
#define S_CLOCKCONFIGURATION_H

class S_ClockConfiguration : public Screen_Menu {
    public:
        S_ClockConfiguration(bool initialConfig, Screen_Menu::MENU_STAGE stage);
        void Update();
    private:
        void HandleInput();
        void SetMachineClock();
        enum Mode {CHANGING_HOURS, CHANGING_MINUTES};
        Mode _currentMode;
        int8_t _hour;
        int8_t _minute;
        bool _initialConfig;
        void ResetTimer(bool isFilled);
        bool _filled;
        uint8_t _ticksToChange;
        void DrawFrame(RgbColor color);
        void DrawHands(RgbColor color);
        void DrawWheel(RgbColor color);

};

#endif