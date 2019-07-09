#include <LedManager.h>
#include <Core.h>
LedManager::LedManager(Core * owner, std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> strip) : Component(owner)
{
    _strip = strip;
    _leds_dirty = true;
    _owner = owner;
}

void LedManager::SetPixels(std::bitset<110> leds, RgbColor color)
{
    std::vector<int> pixels;
    for (int i = 0; i < 110; i++)
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
    for (int led : leds)
    {
        _strip->SetPixelColor(led, color);
    }
    _leds_dirty = true;
}

void LedManager::ClearPixels(RgbColor color){
    _strip->ClearTo(color);
    _leds_dirty = true;
}

void LedManager::Update()
{
    if (_leds_dirty)
    {
        _strip->Show();
        _leds_dirty = false;
    }
}