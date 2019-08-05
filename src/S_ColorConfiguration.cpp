#include <C_EepromManager.h>
#include <C_InputManager.h>
#include <Core.h>
#include <S_ColorConfiguration.h>
#include <S_Menu.h>

S_ColorConfiguration::S_ColorConfiguration() {
    RgbColor color = Core::getInstance()->_eepromManager->GetForegroundColor();
    for (uint8_t i = 0; i < _colorsPalette.size(); i++)
    {
        if(color == _colorsPalette[i]){
            _indexPalette = i;
        }
    }
    
}

void S_ColorConfiguration::Update() {
    HandleInput();
    Core::getInstance()->_ledManager->ClearPixels();
    Core::getInstance()->_ledManager->SetPixel(5, 5, _colorsPalette[_indexPalette]);
}

void S_ColorConfiguration::HandleInput() {
    if (Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::UP)) {
        if (_indexPalette + 1 > _colorsPalette.size()) {
            _indexPalette = 0;
        } else {
            _indexPalette++;
        }
    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::DOWN)) {
        if (_indexPalette - 1 < 0) {
            _indexPalette = _colorsPalette.size()-1;
        } else {
            _indexPalette--;
        }

    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::CONFIRM)) {
        Core::getInstance()->_eepromManager->SetForegroundColor(_colorsPalette[_indexPalette]);
        Core::getInstance()->MoveToScreen(std::make_shared<S_Menu>());

    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::MENU)) {
        Core::getInstance()->MoveToScreen(std::make_shared<S_Menu>());
    }
}