#include <NeoPixelBus.h>
#include <C_LedManager.h>
#include <C_NetworkManager.h>
#include <C_WordMapping.h>
#include <Screen.h>
#include <memory>
#include <vector>

#ifndef CORE_H
#define CORE_H

class Core {
   public:
    virtual ~Core();
    void Update();
    std::shared_ptr<WordMapping> _wordMapping;
    std::shared_ptr<LedManager> _ledManager;
    std::shared_ptr<NetworkManager> _networkManager;
    std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> _strip;
    static Core* getInstance();

   private:
    static Core* instance;
    Core();
    std::vector<std::shared_ptr<Screen>> _screens;
    uint8_t _currentScreenIndex;
    void ChangeScreen(uint8_t screenIndex);
};

#endif