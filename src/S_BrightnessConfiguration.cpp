#include <C_EepromManager.h>
#include <C_InputManager.h>
#include <Core.h>
#include <S_BrightnessConfiguration.h>
#include <S_Menu.h>

std::vector<LedCoord> _circleCoord = {{2, 3}, {2, 4}, {2, 5}, {2, 6}, {3, 2},
                                      {3, 7}, {4, 1}, {4, 8}, {5, 1}, {5, 8},
                                      {6, 1}, {6, 8}, {7, 1}, {7, 8}, {8, 2},
                                      {8, 7}, {9, 3}, {9, 4}, {9, 5}, {9, 6}};

std::vector<std::vector<LedCoord>> _bardsCoord = {
    {{3, 3}, {3, 4}, {3, 5}, {3, 6}},
    {{4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}},
    {{5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}},
    {{6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6}, {6, 7}},
    {{7, 2}, {7, 3}, {7, 4}, {7, 5}, {7, 6}, {7, 7}},
    {{8, 3}, {8, 4}, {8, 5}, {8, 6}}};

S_BrightnessConfiguration::S_BrightnessConfiguration (
    Screen_Menu::MENU_STAGE stage)
    : Screen_Menu(stage), _brightness(0) {
    
}

void S_BrightnessConfiguration::Update() {
    if(_brightness == 0){ _brightness = Core::getInstance()->_eepromManager->GetBrightness();}
    if (CurrentStage == MENU_STAGE::ICON) {
        DrawCircle();
        DrawBars(128); //Half Circle
    } else {
        HandleInput();
        DrawCircle();
        DrawBars(_brightness);
    }
}

void S_BrightnessConfiguration::HandleInput() {
    if (Core::getInstance()->_inputManager->GetKeyDown(C_InputManager::UP)) {
        if (_brightness + BRIGHTNESS_INCREMENT >= 255) {
            _brightness = 255;
        } else {
            _brightness += BRIGHTNESS_INCREMENT;
        }
        Core::getInstance()->_strip->SetBrightness(_brightness);

    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::DOWN)) {
        if (_brightness - BRIGHTNESS_INCREMENT <= 5) {
            _brightness = 5;
        } else {
            _brightness -= BRIGHTNESS_INCREMENT;
        }
        Core::getInstance()->_strip->SetBrightness(_brightness);

    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::CONFIRM)) {
        Core::getInstance()->_eepromManager->SetBrightness(_brightness);
        CurrentStage = ICON;
        Core::getInstance()->_menu->_inSubMenu = false;

    } else if (Core::getInstance()->_inputManager->GetKeyDown(
                   C_InputManager::MENU)) {
        _brightness = Core::getInstance()->_eepromManager->GetBrightness();
        Core::getInstance()->_eepromManager->SetBrightness(_brightness);
        Core::getInstance()->_strip->SetBrightness(_brightness);
        CurrentStage = ICON;
        Core::getInstance()->_menu->_inSubMenu = false;
    }
}

void S_BrightnessConfiguration::DrawCircle() {
    for (uint8_t i = 0; i < _circleCoord.size(); i++) {
        Core::getInstance()->_ledManager->SetPixel(_circleCoord[i],
                                                   RgbColor(255, 255, 255));
    }
}

void S_BrightnessConfiguration::DrawBars(uint8_t brightness) {

    //How many bars
    uint8_t level = (brightness - 5) / 7; // [0,35]
    uint8_t bars = level / 6 ; // [0,5]
    uint8_t intensity = level % 6;

    Serial.print(brightness);
    Serial.print(" : ");
    Serial.print(level);
    Serial.print(" : ");
    Serial.print(intensity);
    Serial.print(" : ");
    Serial.println(bars);

    for(uint8_t i = 0; i <= bars; i++){
        uint8_t colorIntensity; 
        if(i != bars){
            colorIntensity = 255;
        }else{
            colorIntensity = intensity * 255 / 6;
        }
        for(uint8_t led = 0; led < _bardsCoord[i].size(); led++){
            Core::getInstance()->_ledManager->SetPixel(_bardsCoord[i][led],RgbColor(colorIntensity,colorIntensity,colorIntensity));
        }
    }
}