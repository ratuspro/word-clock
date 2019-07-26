#include <C_LedManager.h>
#include <Core.h>
#include <EEPROM.h>
#include <config.h>

LedManager::LedManager() : Component() { _leds_dirty = true; }

void LedManager::SetPixels(std::bitset<NUM_LEDS> leds, RgbColor color) {
    std::vector<int> pixels;
    for (int i = 0; i < leds.size(); i++) {
        if (leds[i] == 1) {
            pixels.push_back(i);
        }
    }
    LedManager::SetPixels(pixels, color);
}

void LedManager::SetPixels(std::vector<int> leds, RgbColor color) {
    for (int led : leds) {
        Core::getInstance()->_strip->SetPixelColor(led, color);
    }
    _leds_dirty = true;
}

void LedManager::ClearPixels(RgbColor color) {
    Core::getInstance()->_strip->ClearTo(color);
    _leds_dirty = true;
}

void LedManager::Update() {
    if (_leds_dirty) {
        Core::getInstance()->_strip->Show();
        _leds_dirty = false;
    }
}

std::shared_ptr<RgbColor> LedManager::GetColorFromEEPROM() {
    EEPROM.readInt(EEPROM_ADDRESS_COLOR_R);
    EEPROM.readInt(EEPROM_ADDRESS_COLOR_G);
    EEPROM.readInt(EEPROM_ADDRESS_COLOR_B);
    return std::make_shared<RgbColor>(EEPROM.readInt(EEPROM_ADDRESS_COLOR_R),
                    EEPROM.readInt(EEPROM_ADDRESS_COLOR_G),
                    EEPROM.readInt(EEPROM_ADDRESS_COLOR_B));
}