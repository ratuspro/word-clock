#include <C_EepromManager.h>
#include <C_InputManager.h>
#include <Core.h>
#include <S_BrightnessConfiguration.h>
#include <S_Menu.h>

S_BrightnessConfiguration::S_BrightnessConfiguration() {
    _brightness = Core::getInstance()->_eepromManager->GetBrightness();
}

void S_BrightnessConfiguration::Update() {
    HandleInput();
    Core::getInstance()->_ledManager->ClearPixels();
    Core::getInstance()->_ledManager->SetPixel(5, 5, RgbColor(255, 0, 0));
}

void S_BrightnessConfiguration::HandleInput() {
    if (Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::UP)) {
        if (_brightness + 25 >= 255) {
            _brightness = 255;
        } else {
            _brightness += 25;
        }
        Core::getInstance()->_strip->SetBrightness(_brightness);

    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::DOWN)) {
        if (_brightness - 25 <= 5) {
            _brightness = 5;
        } else {
            _brightness -= 25;
        }
        Core::getInstance()->_strip->SetBrightness(_brightness);

    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::CONFIRM)) {
        Core::getInstance()->_eepromManager->SetBrightness(_brightness);
        Core::getInstance()->MoveToScreen(std::make_shared<S_Menu>());

    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::MENU)) {
        Core::getInstance()->MoveToScreen(std::make_shared<S_Menu>());
    }
}