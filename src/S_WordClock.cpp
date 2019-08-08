#include <Core.h>
#include <S_WordClock.h>
#include <WiFi.h>
#include <config.h>
#include <time.h>
#include <S_Menu.h>

void S_WordClock::HandleInput(){
    if(Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::MENU)){
        Core::getInstance()->MoveToScreen(Core::getInstance()->_menu);
    }
}

void S_WordClock::Update() {
    if (_currentState == Screen::State::RUNNING) {
        HandleInput();
        struct tm now;
        getLocalTime(&now, 0);
        Core::getInstance()->_ledManager->ClearPixels();
        std::vector<LedCoord> currentTimeLeds = Core::getInstance()->_wordManager->ConvertTimeToPixels(now.tm_hour, now.tm_min);
        Core::getInstance()->_ledManager->SetPixels(
            currentTimeLeds,
            Core::getInstance()->_eepromManager->GetForegroundColor());
    }
}