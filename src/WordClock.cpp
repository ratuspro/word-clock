#include <WordClock.h>
#include <WordMapping.h>
#include <vector>
#include <time.h>

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>* _strip;
WordMapping _wordMapping;

WordClock::WordClock() {}

WordClock::WordClock(NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>* strip) {
    _strip = strip;
    Serial.begin(115200);

}

RgbColor red(255, 0, 0);
RgbColor black(0, 0, 0);

void WordClock::Update() {
    _strip->ClearTo(black);

    std::vector<int> pixels;
    std::vector<int> pixelsToAdd =
        _wordMapping.GetPixel(WordMapping::Word::GAIPS);
    pixels.insert(pixels.end(), pixelsToAdd.begin(), pixelsToAdd.end());

    for (int i = 0; i < pixels.size(); i++) {
        _strip->SetPixelColor(pixels[i], red);
    }

    struct tm timeinfo;
    if (!getLocalTime(&timeinfo)) {
        Serial.println("Failed to obtain time");
    }
    Serial.println("adsasda:" + timeinfo.tm_mon);

    _strip->Show();
}
