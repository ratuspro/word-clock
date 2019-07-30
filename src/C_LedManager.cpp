#include <C_LedManager.h>
#include <Core.h>
#include <EEPROM.h>
#include <config.h>

LedManager::LedManager() : Component(), _leds_dirty(false), _matrixStrip(SCREEN_WIDTH,SCREEN_HEIGHT) { }

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

void LedManager::Test(){
    std::bitset<NUM_LEDS> _screen;
    ClearPixels(RgbColor(0,0,0));
    _screen[_matrixStrip.Map(0,0)] = true;
    _screen[_matrixStrip.Map(1,0)] = true;
    _screen[_matrixStrip.Map(2,0)] = true;
    _screen[_matrixStrip.Map(3,0)] = true;
    _screen[_matrixStrip.Map(4,0)] = true;
    _screen[_matrixStrip.Map(5,0)] = true;
    _screen[_matrixStrip.Map(6,0)] = true;
    _screen[_matrixStrip.Map(7,0)] = true;
    _screen[_matrixStrip.Map(8,0)] = true;
    _screen[_matrixStrip.Map(9,0)] = true;
    _screen[_matrixStrip.Map(10,0)] = true;
    _screen[_matrixStrip.Map(0,1)] = true;
    _screen[_matrixStrip.Map(0,2)] = true;
    _screen[_matrixStrip.Map(0,3)] = true;
    _screen[_matrixStrip.Map(0,4)] = true;
    _screen[_matrixStrip.Map(0,5)] = true;
    _screen[_matrixStrip.Map(0,6)] = true;
    _screen[_matrixStrip.Map(0,7)] = true;
    _screen[_matrixStrip.Map(0,8)] = true;
    _screen[_matrixStrip.Map(0,9)] = true;
    _screen[_matrixStrip.Map(10,9)] = true;
    SetPixels(_screen);
}

std::bitset<NUM_LEDS> LedManager::ConvertFromScreenToBitSet(bool screen[SCREEN_WIDTH][SCREEN_HEIGHT]) {
    std::bitset<NUM_LEDS> _screen;
    for (uint8_t x = 0; x < SCREEN_WIDTH; x++) {
        for (uint8_t y = 0; y < SCREEN_HEIGHT; y++) {
            _screen[_matrixStrip.Map(x,y)] = screen[x][y];
        }
    }
    return _screen;
}

std::bitset<NUM_LEDS> LedManager::CreateScreen(uint8_t deltaX, uint8_t deltaY, std::vector<std::vector<bool>> frame, uint8_t width, uint8_t height) {

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