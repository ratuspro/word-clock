#include <NeoPixelBus.h>

class WordClock {
   public:
    WordClock();
    WordClock(NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>* strip);
    void Update();
};