#include <C_LedManager.h>
#include <Core.h>
#include <EEPROM.h>
#include <config.h>

LedManager::LedManager() : Component() { _leds_dirty = true; }

void LedManager::SetPixels(std::bitset<NUM_LEDS> leds) {
    SetPixels(leds, *GetColorFromEEPROM());
}

void LedManager::SetPixels(std::bitset<NUM_LEDS> leds, RgbColor color) {
    std::vector<int> pixels;
    for (int i = 0; i < leds.size(); i++) {
        if (leds[i] == 1) {
            pixels.push_back(i);
        }
    }
    LedManager::SetPixels(pixels, color);
}

void LedManager::SetPixels(std::vector<int> leds) {
    SetPixels(leds, *GetColorFromEEPROM());
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

std::bitset<NUM_LEDS> LedManager::ConvertFromScreenToBitSet(bool screen[SCREEN_WIDTH][SCREEN_HEIGHT]) {
    std::bitset<NUM_LEDS> _screen;
    for (uint8_t x = 0; x < SCREEN_WIDTH; x++) {
        for (uint8_t y = 0; y < SCREEN_HEIGHT; y++) {
            if(x%2 == 0){
                _screen[x*10 + y] = screen[x][y];
            }else{
                _screen[(x+1)*10 -(y+1)] = screen[x][y];
            }
            //TODO: Can be optimized to one single expression
        }
    }
    return _screen;
}

std::bitset<NUM_LEDS> LedManager::CreateScreen(uint8_t deltaX, uint8_t deltaY, bool **frame, uint8_t width, uint8_t height) {
    std::bitset<NUM_LEDS> _screen;

    bool screen[SCREEN_WIDTH][SCREEN_HEIGHT];
    for (uint8_t x = 0; x < width; x++) {
        for (uint8_t y = 0; y < height; y++) {
            if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT) {
                screen[deltaX + x][deltaY + y] = frame[x][y];
            }
        }
    }

    return ConvertFromScreenToBitSet(screen);
}