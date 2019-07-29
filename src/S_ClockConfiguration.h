#include <Screen.h>
#include <time.h>

class S_ClockConfiguration : public Screen {
    public:
        S_ClockConfiguration();
        void Update();
    private:
        void HandleInput();
        void SetMachineClock();
        enum Mode {CHANGING_HOURS, CHANGING_MINUTES};
        Mode _currentMode;
        uint8_t _hour = 0;
        uint8_t _minute = 0;

};