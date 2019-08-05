#include <Screen.h>

class S_BrightnessConfiguration : public Screen {
   public:
    S_BrightnessConfiguration();
    void Update();
    void HandleInput();

   private:
    uint8_t _brightness;
};