#include <LedManager.h>
#include <Core.h>
#include <config.h>
LedManager::LedManager(Core * owner, std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> strip) : Component(owner)
{
    _strip = strip;
    _leds_dirty = true;
    _owner = owner;
}

void LedManager::SetPixels(std::bitset<NUM_LEDS> leds, RgbColor color)
{
    Serial.println("Start conversion");
    std::vector<int> pixels;
    Serial.println("Start conversion2");
    for (int i = 0; i < leds.size(); i++)
    {
        
        if (leds[i] == 1)
        {
            pixels.push_back(i);
        }
    }
    LedManager::SetPixels(pixels, color);
}

void LedManager::SetPixels(std::vector<int> leds, RgbColor color)
{
    Serial.println("Changing Leds");
    for (int led : leds)
    {
        _strip->SetPixelColor(led, color);
    }
    _leds_dirty = true;
}

void LedManager::ClearPixels(RgbColor color){
    Serial.println("Clearing Leds");
    _strip->ClearTo(color);
    _leds_dirty = true;
    Serial.println("Ended Clearing Leds");
}

void LedManager::Update()
{
    if (_leds_dirty)
    {
        _strip->Show();
        _leds_dirty = false;
    }
}