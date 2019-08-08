#include <C_EepromManager.h>
#include <C_InputManager.h>
#include <Core.h>
#include <S_ColorConfiguration.h>
#include <S_Menu.h>

std::vector<LedCoord> _brushCoord = {{3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0},
                                     {3, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1},
                                     {3, 2}, {4, 2}, {5, 2}, {6, 2}, {7, 2}};

std::vector<LedCoord> _handleCoord = {
    {8, 1}, {9, 1}, {9, 2}, {9, 3}, {9, 4}, {8, 4}, {7, 4}, {6, 4},
    {5, 4}, {5, 5}, {5, 6}, {6, 6}, {6, 7}, {6, 8}, {6, 9}, {5, 9},
    {4, 9}, {4, 8}, {5, 8}, {5, 7}, {4, 7}, {4, 6}};

S_ColorConfiguration::S_ColorConfiguration(Screen_Menu::MENU_STAGE stage)
    : Screen_Menu(stage), _indexPalette(99) {}

void S_ColorConfiguration::Update() {
    if (_indexPalette == 99) {
        RgbColor color =
            Core::getInstance()->_eepromManager->GetForegroundColor();
        for (uint8_t i = 0; i < _colorsPalette.size(); i++) {
            if (color == _colorsPalette[i]) {
                _indexPalette = i;
            }
        }
    }

    // Drawing
    if (CurrentStage == MENU_STAGE::ICON) {
        DrawBrush(_colorsPalette[_indexPalette]);
        DrawHandle(false);
    } else {
        HandleInput();
        DrawBrush(_colorsPalette[_indexPalette]);
        DrawHandle(true);
    }
}

void S_ColorConfiguration::HandleInput() {
    if (Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::UP)) {
        if (_indexPalette + 1 >= _colorsPalette.size()) {
            _indexPalette = 0;
        } else {
            _indexPalette++;
        }
    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::DOWN)) {
        if (_indexPalette - 1 < 0) {
            _indexPalette = _colorsPalette.size() - 1;
        } else {
            _indexPalette--;
        }

    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::CONFIRM)) {
        Core::getInstance()->_eepromManager->SetForegroundColor(
            _colorsPalette[_indexPalette]);
        ExitScreen();

    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::MENU)) {
        ExitScreen();
    }
}

void S_ColorConfiguration::DrawBrush(RgbColor color) {
    Core::getInstance()->_ledManager->SetPixels(_brushCoord, color);
}

void S_ColorConfiguration::DrawHandle(bool colored) {
    uint8_t handlePallete = (_indexPalette + 1) % _colorsPalette.size();
    for (uint8_t handleIndex = 0; handleIndex < _handleCoord.size();
         handleIndex++) {
        if (colored) {
            Core::getInstance()->_ledManager->SetPixel(
                _handleCoord[handleIndex], _colorsPalette[handlePallete]);
            handlePallete = (handlePallete + 1) % _colorsPalette.size();
        } else {
            Core::getInstance()->_ledManager->SetPixel(
                _handleCoord[handleIndex], RgbColor(255, 255, 255));
        }
    }
}