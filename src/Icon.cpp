#include <Core.h>
#include <Icon.h>

void Icon::Update() {
    Core::getInstance()->_ledManager->SetPixel(
        5, 5, Core::getInstance()->_eepromManager->GetForegroundColor());
}