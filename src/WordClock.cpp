#include <WordClock.h>
#include <WordMapping.h>
#include <vector>

NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>* _strip;
WordMapping _wordMapping;

WordClock::WordClock() {}

WordClock::WordClock(NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>* strip) {
    _strip = strip;
    Serial.begin(115200);
}

RgbColor red(255, 0, 0);
RgbColor black(0, 0, 0);

void FillLedsAndShow(std::vector<int> leds, RgbColor color,
                     RgbColor background = black) {
    _strip->ClearTo(background);
    for (int led : leds) {
        _strip->SetPixelColor(led, color);
    }
    _strip->Show();
}

void WordClock::Update() {
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::GAIPS), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_EIGHT), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_ELEVEN), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_FIVE), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_FOUR), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_NINE), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_ONE), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_SEVEN), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_SIX), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_TEN), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_THREE), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_TWELVE), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::H_TWO), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::IT_S), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::M_A_QUARTER), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::M_FIVE), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::M_HALF), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::M_TEN), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::M_TWENTY), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::O_CLOCK), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::PAST), red);
    delay(1000);
    FillLedsAndShow(_wordMapping.GetLeds(WordMapping::Word::TO), red);
}


