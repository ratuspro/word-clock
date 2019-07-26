#include <Screen.h>
#include <config.h>
#include <bitset>
#include <memory>

class S_StartingScreen : public Screen {
   public:
    S_StartingScreen();
    void Update();
  private:
    void UpdateAnimation();
    // Word
    std::bitset<NUM_LEDS> _word;
    int _numberOfFades;
    bool _increasing = true;
    float _progress = 0;
    std::shared_ptr<RgbColor> _initialColor;
    std::shared_ptr<RgbColor> _targetColor; 

    // WiFi
    int _numberOfWifiAttempts;

    // Timers
    int _numAttempts;
    clock_t _lastAttempt;

};