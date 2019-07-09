#include <bitset>
#include <vector>
#include <NeoPixelBus.h>
#include <memory>
#include <Component.h>

#ifndef LEDMANAGER_H
#define LEDMANAGER_H

class LedManager : Component{
    public:
        LedManager(class Core* owner, std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> strip);
        void SetPixels(std::bitset<110> leds, RgbColor color);
        void SetPixels(std::vector<int> leds, RgbColor color);
        void ClearPixels(RgbColor color);
        void Update();
    private:
        std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> _strip;
        bool _leds_dirty;
};

#endif