#include <C_LedManager.h>
#include <C_WordManager.h>
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

    // Init EEPROM 
    if (!EEPROM.begin(EEPROM_SIZE)) {
        Serial.println("failed to initialise EEPROM");
        ESP.restart();
    }

    // Init Strip
    _strip = std::make_shared<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>>(
        NUM_LEDS, LEDS_PIN);
    _strip->Begin();

    // Init Buttons
    _inputManager = std::make_shared<C_InputManager>();
    _inputManager->AddButton(C_InputManager::ButtonName::MENU, BUTTON4_PIN);
    _inputManager->AddButton(C_InputManager::ButtonName::UP, BUTTON1_PIN);
    _inputManager->AddButton(C_InputManager::ButtonName::DOWN, BUTTON2_PIN);
    _inputManager->AddButton(C_InputManager::ButtonName::CONFIRM, BUTTON3_PIN);
    
    // Add Word Mapping
    _C_WordManager = std::make_shared<C_WordManager>();

    // Add Word Led Manager
    _ledManager = std::make_shared<LedManager>();

    // Add network Manager
    _networkManager = std::make_shared<C_NetworkManager>();

    // Add Icon Manager
    _iconManager = std::make_shared<C_IconManager>();

    // Start Screen
    Core::MoveToScreen(std::make_shared<S_StartingScreen>());

}

Core::~Core() {}

void Core::Update() {
    _currentScreen->Update();
    _ledManager->Update();
    _inputManager->Update();
    delay(1000 / FRAME_RATE);
}

void Core::MoveToScreen(std::shared_ptr<Screen> nextScreen) {
    if (_currentScreen) {
        _currentScreen->Stop();
    }
    _currentScreen = nextScreen;
    _currentScreen->Run();
}