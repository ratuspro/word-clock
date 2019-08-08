#include <Screen.h>
#include <config.h>
#include <bitset>
#include <memory>

#ifndef S_STRATINGSCREEN_H
#define S_STRATINGSCREEN_H

class S_StartingScreen : public Screen {
   public:
    S_StartingScreen();
    void Update();
  private:
    void UpdateAnimation();
    // Word
    std::vector<LedCoord> _word;
    int _numberOfFades;
    bool _increasing = true;
    float _progress = 0;
    RgbColor _initialColor;
    RgbColor _targetColor; 

    // WiFi
    int _numberOfWifiAttempts;

    // Timers
    int _numAttempts;
    clock_t _lastAttempt;

};

#endif