#include <Core.h>
#include <S_ClockConfiguration.h>

void S_ClockConfiguration::Update() {
    Core::getInstance()->_ledManager->SetPixels(
        Core::getInstance()->_wordMapping->GetLeds(
            Core::getInstance()->_wordMapping->IT_S),
        *Core::getInstance()->_ledManager->GetColorFromEEPROM());
}