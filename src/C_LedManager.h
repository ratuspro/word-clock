#include <bitset>
#include <vector>
#include <NeoPixelBus.h>
#include <memory>
#include <Component.h>
#include <config.h>


#ifndef LEDMANAGER_H
#define LEDMANAGER_H

struct LedCoord{
    public:
        uint8_t x;
        uint8_t y;
};

class C_LedManager : Component{
    public:
        C_LedManager();
        void Update();
        void ClearPixels();
        void SetAllPixels(RgbColor color);
        void SetPixel(LedCoord coord, RgbColor color);
        void SetPixels(std::vector<LedCoord> coords, RgbColor color);
    private:
        std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> _strip;
        NeoTopology<RowMajorAlternating270Layout> _matrixStrip;
        bool _leds_dirty;
};

#endif