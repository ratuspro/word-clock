#include <Screen_Menu.h>

#ifndef S_BRIGHTNESSCONFIGURATION_H
#define S_BRIGHTNESSCONFIGURATION_H

class S_BrightnessConfiguration : public Screen_Menu {
   public:
    S_BrightnessConfiguration(Screen_Menu::MENU_STAGE stage = Screen_Menu::MENU_STAGE::ICON);
    void Update();
    void HandleInput();

   private:
    uint8_t _brightness;
    RgbColor _referenceColor;
    void DrawCircle(RgbColor color);
    void DrawBars(uint8_t brightness, RgbColor color);
};

#endif