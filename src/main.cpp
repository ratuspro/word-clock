#include <AceButton.h>
#include <NeoPixelAnimator.h>
#include <NeoPixelBus.h>
#include <Core.h>
#include <config.h>
#include <memory>

using namespace std;

// Strip
shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> _strip;

// Buttons
ace_button::AceButton Buttons[NUM_BUTTONS];

// Word Clock Core
shared_ptr<Core> _core;

void setup() {

    _strip = make_shared<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>>(NUM_LEDS, LEDS_PIN);
    _core = make_shared<Core>(_strip);
    
    // To avoid power problems
    delay(2000);
    Serial.begin(115200);
    _strip->Begin();

    // Define IO
    /*pinMode(ButtonTop1Pin, INPUT);
    Buttons[0].init(ButtonTop1Pin);
    pinMode(ButtonTop2Pin, INPUT);
    Buttons[1].init(ButtonTop2Pin);
    pinMode(ButtonTop3Pin, INPUT);
    Buttons[2].init(ButtonTop3Pin);
    pinMode(ButtonTop4Pin, INPUT);
    Buttons[3].init(ButtonTop4Pin);*/
}

void loop() {

    for (int i = 0; i < NUM_BUTTONS; i++) {
        Buttons[i].check();
    }

    _core->Update();
        
}