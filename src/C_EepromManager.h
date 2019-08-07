#include <Component.h>
#include <NeoPixelBrightnessBus.h>

#ifndef C_EEPROMMANAGER_H
#define C_EEPROMMANAGER_H

class C_EepromManager : public Component {
   public:
    C_EepromManager();
    RgbColor GetForegroundColor();
    void SetForegroundColor(RgbColor color);
    uint8_t GetBrightness();
    void SetBrightness(uint8_t value);
    void PrintAll();
};

#endif