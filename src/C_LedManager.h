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
        void SetPixels(std::bitset<NUM_LEDS> leds);
        void SetPixels(std::bitset<NUM_LEDS> leds, RgbColor color);
        void SetPixels(std::vector<int> leds);
        void SetPixels(std::vector<int> leds, RgbColor color);
        void ClearPixels(RgbColor color);
        void Update();
        std::shared_ptr<RgbColor> GetColorFromEEPROM();
        std::bitset<NUM_LEDS> ConvertFromScreenToBitSet(bool screen[SCREEN_WIDTH][SCREEN_HEIGHT]);
        std::bitset<NUM_LEDS> CreateScreen(uint8_t deltaX, uint8_t deltaY, std::vector<std::vector<bool>> frame, uint8_t width, uint8_t height);
    private:
        bool _leds_dirty;
        NeoTopology<RowMajor270Layout> _matrixStrip;
        
};

#endif