#include <Screen.h>
#include <bitset>
#include <config.h>

class S_WordClock : public Screen {
   public:
    S_WordClock(class Core* core);
    void Update();

   private:
    bool _timeSet;
    std::bitset<NUM_LEDS> ConvertTimeToLeds(struct tm time);
};