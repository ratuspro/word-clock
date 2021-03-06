#include <bitset>
#include <vector>
#include <memory>
#include <Component.h>
#include <config.h>
#include <NeoPixelBrightnessBus.h>

#ifndef LEDMANAGER_H
#define LEDMANAGER_H

struct LedCoord{
    public:
        uint8_t x;
        uint8_t y;
};

class C_LedManager : Component{
    public:
        C_LedManager(std::shared_ptr<NeoPixelBrightnessBus<NeoGrbFeature, Neo800KbpsMethod>> strip);
        void Update();
        void ClearPixels();
        void SetAllPixels(RgbColor color);
        void SetPixel(LedCoord coord, RgbColor color);
        void SetPixel(uint8_t xPosition, uint8_t yPosition, RgbColor color);
        void SetPixels(std::vector<LedCoord> coords, RgbColor color);
        void SetPixels(std::vector<LedCoord> coords, RgbColor color, uint8_t xOffset, uint8_t yOffset);
    private:
        std::shared_ptr<NeoPixelBrightnessBus<NeoGrbFeature, Neo800KbpsMethod>> _strip;
        NeoTopology<RowMajorAlternating270Layout> _matrixStrip;
        bool _leds_dirty;
};

#endif