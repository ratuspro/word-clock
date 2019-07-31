#include <Screen.h>
#include <time.h>
#include <C_LedManager.h>
#include <C_InputManager.h>

class S_ClockConfiguration : public Screen {
    public:
        S_ClockConfiguration();
        void Update();
    private:
        std::shared_ptr<C_InputManager> _inputManager;
        std::shared_ptr<C_LedManager> _ledManager;
        void HandleInput();
        void SetMachineClock();
        enum Mode {CHANGING_HOURS, CHANGING_MINUTES};
        Mode _currentMode;
        int8_t _hour;
        int8_t _minute;
        
        void ResetTimer(bool isFilled);
        bool _filled;
        uint8_t _ticksToChange;

};