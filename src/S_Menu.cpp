#include <Core.h>
#include <S_ClockConfiguration.h>
#include <S_Menu.h>
#include <Icon.h>

S_Menu::S_Menu() {
    addEntry("time", std::make_shared<S_ClockConfiguration>());
    addEntry("color", std::make_shared<S_ClockConfiguration>());
    addEntry("brightness", std::make_shared<S_ClockConfiguration>());
    addEntry("wifi", std::make_shared<S_ClockConfiguration>());
    _selectedEntry = 0;
}

void S_Menu::Update() {
    HandleInput();
    
    Core::getInstance()->_ledManager->ClearPixels(RgbColor(0,0,0));
    Icon currentIcon = Core::getInstance()->_iconManager->GetFrame(_entries[_selectedEntry].iconName,1);
    Core::getInstance()->_ledManager->SetPixels(Core::getInstance()->_ledManager->CreateScreen(2,2,currentIcon._frame, ICON_WIDTH, ICON_HEIGHT));

}

void S_Menu::addEntry(std::string iconName, std::shared_ptr<Screen> screen) {
    MenuEntry entry;
    entry.iconName = iconName;
    entry.screen = screen;
    _entries.push_back(entry);
}

void S_Menu::HandleInput() {
    if (Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::UP)) {
        _selectedEntry++;
        if(_selectedEntry >= _entries.size()){ _selectedEntry = 0; }
    } else if (Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::DOWN)) {
        if(_selectedEntry < 0){ _selectedEntry = _entries.size(); }
    } else if (Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::CONFIRM)) {
        Core::getInstance()->MoveToScreen(_entries[_selectedEntry].screen);
    }
}
