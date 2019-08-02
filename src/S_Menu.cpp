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
    Core::getInstance()->_ledManager->ClearPixels();
    Icon icon = Core::getInstance()->_iconManager->GetFrame(
        _entries[_selectedEntry].iconName);
    Core::getInstance()->_ledManager->SetPixels(
            icon.GetPixelsCoordinates(),
            Core::getInstance()->_eepromManager->GetForegroundColor());
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
