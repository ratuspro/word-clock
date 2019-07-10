#include <Core.h>
#include <LedManager.h>
#include <S_WordClock.h>
#include <Screen.h>
#include <WordMapping.h>
#include <config.h>
#include <vector>

// Constructor
Core::Core(
    std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> strip) {
    _strip = strip;

    // Add Word Mapping
    _wordMapping = std::make_shared<WordMapping>(this);

    // Add Word Led Manager
    _ledManager = std::make_shared<LedManager>(this, _strip);

    // Add Networking Manager
    _networkManager = std::make_shared<NetworkManager>(this);
    _networkManager->Setup();

    // Add Word Clock Screen
    _screens.push_back(
        std::dynamic_pointer_cast<Screen>(std::make_shared<S_WordClock>(this)));
    ChangeScreen(0);
}

Core::~Core() {}

void Core::Update() {

    // Update Current Screen
    Serial.println("Updating current screen");
    _screens[_currentScreenIndex]->Update();

    // Update Leds
    Serial.println("Updating leds");
    _ledManager->Update();

    // Wait
    delay(1000 / FRAME_RATE);
}

void Core::ChangeScreen(uint8_t screenIndex){
    _currentScreenIndex = screenIndex;
    _screens[_currentScreenIndex]->Run();
}