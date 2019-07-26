#include <C_LedManager.h>
#include <C_WordMapping.h>
#include <Core.h>
#include <EEPROM.h>
#include <S_StartingScreen.h>
#include <S_WordClock.h>
#include <Screen.h>
#include <config.h>
#include <vector>

Core* Core::instance = 0;

Core* Core::getInstance() {
    if (instance == 0) {
        Serial.println("Created Core");
        instance = new Core();
    }
    return instance;
}

// Constructor
Core::Core() {

    if (!EEPROM.begin(EEPROM_SIZE)) {
        Serial.println("failed to initialise EEPROM");
        ESP.restart();
    }

    _strip = std::make_shared<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>>(
        NUM_LEDS, LEDS_PIN);
    _strip->Begin();

    // Add Word Mapping
    _wordMapping = std::make_shared<WordMapping>();

    // Add Word Led Manager
    _ledManager = std::make_shared<LedManager>();

    // Add network Manager
    _networkManager = std::make_shared<C_NetworkManager>();

    Core::MoveToScreen(std::make_shared<S_StartingScreen>());
}

Core::~Core() {}

void Core::Update() {
    _currentScreen->Update();
    _ledManager->Update();
    delay(1000 / FRAME_RATE);
}

void Core::MoveToScreen(std::shared_ptr<Screen> nextScreen) {
    if (_currentScreen) {
        _currentScreen->Stop();
    }
    _currentScreen = nextScreen;
    _currentScreen->Run();
}