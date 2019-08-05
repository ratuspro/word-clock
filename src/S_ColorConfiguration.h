#include <Screen.h>

class S_ColorConfiguration : public Screen {
   public:
    S_ColorConfiguration();
    void Update();

   private:
    void HandleInput();
    uint8_t _indexPalette = 0;
    std::vector<RgbColor> _colorsPalette = {
        RgbColor(255, 0, 0), RgbColor(0, 255, 0), RgbColor(0, 0, 255)};
};