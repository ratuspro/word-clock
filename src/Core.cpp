#include <Core.h>
#include <vector>
#include <WordMapping.h>
#include <LedManager.h>
#include <S_WordClock.h>
#include <Screen.h>

//Constructor
Core::Core(std::shared_ptr<NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod>> strip) {
    _strip = strip;

    // Add Word Mapping
    _wordMapping = std::make_shared<WordMapping>(this);
    
    // Add Word Led Manager
    _ledManager = std::make_shared<LedManager>(this, _strip);
    
    // Add Networking Manager
    _networkManager = std::make_shared<NetworkManager>(this);
    _networkManager->Setup();

    // Add Word Clock Screen
    _screens.push_back(std::dynamic_pointer_cast<Screen>(std::make_shared<S_WordClock>(this)));

    _currentScreenIndex = 0;
}

Core::~Core(){
    
}

RgbColor red(255, 0, 0);
RgbColor black(0, 0, 0);

void Core::Update() {
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::GAIPS), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_EIGHT), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_ELEVEN), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_FIVE), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_FOUR), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_NINE), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_ONE), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_SEVEN), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_SIX), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_TEN), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_THREE), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_TWELVE), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::H_TWO), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::IT_S), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::M_A_QUARTER), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::M_FIVE), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::M_HALF), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::M_TEN), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::M_TWENTY), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::O_CLOCK), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::PAST), red);
    _ledManager->Update();
    delay(1000);
    _ledManager->SetPixels(_wordMapping->GetLeds(WordMapping::Word::TO), red);
    _ledManager->Update();
}


