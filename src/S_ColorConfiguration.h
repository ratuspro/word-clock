#include <Screen.h>

class S_ColorConfiguration : public Screen {
   public:
    S_ColorConfiguration();
    void Update();

   private:
    void HandleInput();
    uint8_t _indexPalette = 0;
    std::vector<RgbColor> _colorsPalette = {
        RgbColor(244, 67, 54),  RgbColor(233, 30, 99),  RgbColor(156, 39, 176),
        RgbColor(103, 58, 183), RgbColor(63, 81, 181),  RgbColor(33, 150, 243),
        RgbColor(3, 169, 244),  RgbColor(0, 188, 212),  RgbColor(0, 150, 136),
        RgbColor(76, 175, 80),  RgbColor(139, 195, 74), RgbColor(205, 220, 57),
        RgbColor(255, 235, 59), RgbColor(255, 193, 7),  RgbColor(255, 152, 0),
        RgbColor(255, 87, 34),  RgbColor(121, 85, 72),  RgbColor(158, 158, 158),
        RgbColor(96, 125, 139), RgbColor(255, 255, 255)};
};