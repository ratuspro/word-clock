#include <Core.h>
#include <config.h>

// Word Clock Core
Core * _core;

void setup() {

    // To avoid power problems
    delay(STARTUP_DELAY);
    Serial.begin(115200);
    
    // Init and get Core Instance
    _core = Core::getInstance();

}

void loop() {
    _core->Update();       
}