#include <Screen.h>
#include <config.h>
#include <bitset>

class S_WordClock : public Screen {
   public:
    void Update();
    void HandleInput();
    static std::bitset<NUM_LEDS> ConvertTimeToLeds(int hours, int minutes);
   private:
    bool _timeSet;
};