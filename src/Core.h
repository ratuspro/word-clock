#include <LedManager.h>
#include <NeoPixelBus.h>
#include <NetworkManager.h>
#include <Screen.h>
#include <WordMapping.h>
#include <memory>
#include <vector>

#ifndef CORE_H
#define CORE_H

class Core {
   public:
    Core(std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> strip);
    virtual ~Core();
    void Update();
    std::shared_ptr<WordMapping> _wordMapping;
    std::shared_ptr<LedManager> _ledManager;
    std::shared_ptr<NetworkManager> _networkManager;

   private:
    std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> _strip;
    std::vector<std::shared_ptr<Screen>> _screens;
    uint8_t _currentScreenIndex;
};

#endif