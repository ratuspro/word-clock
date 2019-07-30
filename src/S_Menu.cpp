#include <Core.h>
#include <Icon.h>
#include <S_ClockConfiguration.h>
#include <S_Menu.h>

S_Menu::S_Menu() {
    addEntry("time", std::make_shared<S_ClockConfiguration>());
    _selectedEntry = 0;
}

void S_Menu::Update() {
    HandleInput();

    // Get one icon
    Core::getInstance()->_ledManager->ClearPixels(RgbColor(0,0,0));
    Icon icon = Core::getInstance()->_iconManager->GetFrame(_entries[_selectedEntry].iconName);
    Core::getInstance()->_ledManager->SetPixels(Core::getInstance()->_ledManager->CreateScreen(0,0,icon._frame,ICON_WIDTH,ICON_HEIGHT));
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
        if (_selectedEntry >= _entries.size()) {
            _selectedEntry = 0;
        }
    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::DOWN)) {
        if (_selectedEntry < 0) {
            _selectedEntry = _entries.size();
        }
    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::CONFIRM)) {
        Core::getInstance()->MoveToScreen(_entries[_selectedEntry].screen);
    }
}
