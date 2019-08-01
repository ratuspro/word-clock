#include <C_LedManager.h>
#include <C_WordManager.h>
#include <NeoPixelBus.h>
#include <Screen.h>
#include <memory>
#include <vector>
#include <C_NetworkManager.h>
#include <C_InputManager.h>
#include <C_IconManager.h>
#include <C_EepromManager.h>

#ifndef CORE_H
#define CORE_H

class Core {
   public:
    virtual ~Core();
    void Update();
    void MoveToScreen(std::shared_ptr<Screen> nextScreen);
    std::shared_ptr<C_WordManager> _wordManager;
    std::shared_ptr<C_LedManager> _ledManager;
    std::shared_ptr<C_NetworkManager> _networkManager;
    std::shared_ptr<C_InputManager> _inputManager;
    std::shared_ptr<C_IconManager> _iconManager;
    std::shared_ptr<C_EepromManager> _eepromManager;
    std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> _strip;
    static Core* getInstance();
   private:
    static Core* instance;
    Core();
    std::shared_ptr<Screen> _currentScreen;
};

#endif