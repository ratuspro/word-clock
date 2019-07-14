#include <bitset>
#include <vector>
#include <NeoPixelBus.h>
#include <memory>
#include <Component.h>
#include <config.h>

#ifndef LEDMANAGER_H
#define LEDMANAGER_H

class LedManager : Component{
    public:
        LedManager();
        void SetPixels(std::bitset<NUM_LEDS> leds, RgbColor color);
        void SetPixels(std::vector<int> leds, RgbColor color);
        void ClearPixels(RgbColor color);
        void Update();
    private:
        bool _leds_dirty;
};

#endif