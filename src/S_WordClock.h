#include <Screen.h>
#include <config.h>
#include <bitset>

class S_WordClock : public Screen {
   public:
    void Update();

   private:
    bool _timeSet;
    std::bitset<NUM_LEDS> ConvertTimeToLeds(int hours, int minutes);
};