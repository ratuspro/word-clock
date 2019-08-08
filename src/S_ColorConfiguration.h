#include <C_LedManager.h>
#include <Screen_Menu.h>
#include <vector>

#ifndef S_COLORCONFIGURATION_H
#define S_COLORCONFIGURATION_H

class S_ColorConfiguration : public Screen_Menu {
   public:
    S_ColorConfiguration(
        Screen_Menu::MENU_STAGE stage = Screen_Menu::MENU_STAGE::ICON);
    void Update();
    std::vector<RgbColor> _colorsPalette = {
        RgbColor(254, 0, 177),RgbColor(252, 14, 52),RgbColor(255, 207, 9),
        RgbColor(0, 255, 198),RgbColor(15, 240, 255), RgbColor(204, 255, 0),
        RgbColor(102, 0, 255),RgbColor(255, 100, 0), RgbColor(8, 255, 8),
        RgbColor(230, 0, 0),RgbColor(57, 255, 20), RgbColor(63, 0, 255),
        RgbColor(254, 20, 147), RgbColor(176, 5, 75), RgbColor(254, 68, 0),
        RgbColor(207, 255, 4), RgbColor(255, 0, 0), RgbColor(0, 255, 0), 
        RgbColor(0, 0, 255), RgbColor(255, 255, 255)};

   private:
    void HandleInput();
    uint8_t _indexPalette = 0;
    void DrawBrush(RgbColor color);
    void DrawHandle(bool colored);
};

#endif