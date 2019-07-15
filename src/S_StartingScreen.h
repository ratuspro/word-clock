#include <Screen.h>
#include <config.h>
#include <bitset>

class S_StartingScreen : public Screen {
   public:
    S_StartingScreen();
    void Update();
  private:
    std::bitset<NUM_LEDS> _word;
    int _numberOfFades;
    bool _increasing = true;
    float _progress = 0;
    RgbColor* _initialColor;
    RgbColor* _targetColor;
};