#include <AceButton.h>
#include <NeoPixelAnimator.h>
#include <NeoPixelBus.h>
#include <WordClock.h>

using namespace ace_button;

// Strip
const uint16_t PixelCount = 110;
const uint8_t PixelPin = 5;
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

// Buttons
const uint8_t Num_Buttons = 4;
const uint8_t ButtonTop1Pin = 27;
const uint8_t ButtonTop2Pin = 13;
const uint8_t ButtonTop3Pin = 14;
const uint8_t ButtonTop4Pin = 15;
AceButton Buttons[4];

// Word Clock
WordClock _wc(&strip);

void setup() {
    // Avoid power problems
    delay(3000);

    // Setup Strip
    strip.Begin();
    strip.Show();

    // Define IO
    pinMode(ButtonTop1Pin, INPUT);
    Buttons[0].init(ButtonTop1Pin);
    pinMode(ButtonTop2Pin, INPUT);
    Buttons[1].init(ButtonTop2Pin);
    pinMode(ButtonTop3Pin, INPUT);
    Buttons[2].init(ButtonTop3Pin);
    pinMode(ButtonTop4Pin, INPUT);
    Buttons[3].init(ButtonTop4Pin);

}

void loop() {

    for (int i = 0; i < Num_Buttons; i++) {
        Buttons[i].check();
    }

    _wc.Update();
        
}