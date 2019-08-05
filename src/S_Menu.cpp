#include <C_LedManager.h>
#include <Core.h>
#include <Icon.h>
#include <S_BrightnessConfiguration.h>
#include <S_ClockConfiguration.h>
#include <S_ColorConfiguration.h>
#include <S_Menu.h>
#include <S_NetworkConfiguration.h>
#include <config.h>
#include <S_WordClock.h>

S_Menu::S_Menu() {
    addEntry("time", std::make_shared<S_ClockConfiguration>());
    addEntry("time", std::make_shared<S_ColorConfiguration>());
    addEntry("brightness", std::make_shared<S_BrightnessConfiguration>());
    addEntry("time", std::make_shared<S_NetworkConfiguration>());
    _selectedEntry = 0;
    _inSubMenu = false;
}

void S_Menu::Update() {

    HandleInput();

    Core::getInstance()->_ledManager->ClearPixels();
    DrawSidebar();
    DrawIcon();
   
}

void S_Menu::addEntry(std::string iconName, std::shared_ptr<Screen> screen) {
    MenuEntry entry;
    entry.iconName = iconName;
    entry.screen = screen;
    _entries.push_back(entry);
}

void S_Menu::HandleInput() {
    if (Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::DOWN)) {
        _selectedEntry++;
        if (_selectedEntry >= _entries.size()) {
            _selectedEntry = 0;
        }
    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::UP)) {
        _selectedEntry--;
        if (_selectedEntry > _entries.size()) {
            _selectedEntry = _entries.size() -1;
        }
    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::CONFIRM)) {
        Core::getInstance()->MoveToScreen(_entries[_selectedEntry].screen);
    }else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::MENU)) {
        Core::getInstance()->MoveToScreen(std::make_shared<S_WordClock>());
    }
}

void S_Menu::DrawSidebar() {
    uint8_t sidebarNumPixels = SCREEN_HEIGHT;
    uint8_t sidebarSpace =
        (sidebarNumPixels - _entries.size()) / (_entries.size() - 1);
    for (uint8_t entry = 0; entry < _entries.size(); entry++) {
        uint8_t pos = entry * sidebarSpace + entry;
        LedCoord entryCoord = {0, pos};
        RgbColor color =
            Core::getInstance()->_eepromManager->GetForegroundColor();
        if (_selectedEntry == entry) {
            color.Lighten(100);
        }
        Core::getInstance()->_ledManager->SetPixel(entryCoord, color);
    }
}

void S_Menu::DrawIcon() {
    Icon CurrentIcon = Core::getInstance()->_iconManager->GetFrame(_entries[_selectedEntry].iconName);
    Core::getInstance()->_ledManager->SetPixels(CurrentIcon.GetPixelsCoordinates(), Core::getInstance()->_eepromManager->GetForegroundColor(),2,1);
}