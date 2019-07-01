#include <WordClock.h>

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>* _strip;

WordClock::WordClock() {}

WordClock::WordClock(NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>* strip) {
    _strip = strip;
}

void WordClock::Update() {}