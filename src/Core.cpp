#include <Core.h>
#include <LedManager.h>
#include <S_WordClock.h>
#include <Screen.h>
#include <WordMapping.h>
#include <config.h>
#include <vector>

Core* Core::instance = 0;

Core* Core::getInstance(){
    if(instance == 0){
        instance = new Core();
    }
    return instance;
}

// Constructor
Core::Core() {
    _strip = std::make_shared<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>>(NUM_LEDS, LEDS_PIN);
    _strip->Begin();

    // Add Word Mapping
    _wordMapping = std::make_shared<WordMapping>();

    // Add Word Led Manager
    _ledManager = std::make_shared<LedManager>();

    // Add Networking Manager
    _networkManager = std::make_shared<NetworkManager>();
    _networkManager->Setup();

    // Add Word Clock Screen
    _screens.push_back(
        std::dynamic_pointer_cast<Screen>(std::make_shared<S_WordClock>()));
    ChangeScreen(0);
}

Core::~Core() {}

void Core::Update() {

    // Update Current Screen
    Serial.println("Updating current screen" + _currentScreenIndex);
    _screens[_currentScreenIndex]->Update();

    // Update Leds
    Serial.println("Updating leds");
    _ledManager->Update();

    // Wait
    delay(1000/ FRAME_RATE);
}

void Core::ChangeScreen(uint8_t screenIndex){
    _currentScreenIndex = screenIndex;
    _screens[_currentScreenIndex]->Run();
}