#include <C_LedManager.h>
#include <Core.h>
#include <EEPROM.h>
#include <config.h>

C_LedManager::C_LedManager(std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> strip)
    : Component(),
      _matrixStrip(SCREEN_WIDTH, SCREEN_HEIGHT),
      _leds_dirty(false) {
    _strip = strip;
}

void C_LedManager::Update() {
    if (_leds_dirty) {
        _strip->Show();
        _leds_dirty = false;
    }
}

void C_LedManager::ClearPixels() {
    // set all pixels to black
    SetAllPixels(RgbColor(0, 0, 0));
}

void C_LedManager::SetAllPixels(RgbColor color) {
    for (uint8_t pixelIndex = 0; pixelIndex < NUM_LEDS; pixelIndex++) {
        _strip->SetPixelColor(pixelIndex, color);
    }
    _leds_dirty = true;
}

void C_LedManager::SetPixel(LedCoord coord, RgbColor color) {
    uint8_t pixelIndex = _matrixStrip.Map(coord.x, coord.y);
    if (_strip->GetPixelColor(pixelIndex) == color) {
        return;
    }
    _strip->SetPixelColor(pixelIndex, color);
    _leds_dirty = true;
}

void C_LedManager::SetPixels(std::vector<LedCoord> coords, RgbColor color) {
    for (uint8_t i = 0; i < coords.size(); i++) {
        SetPixel(coords[i], color);
    }
}