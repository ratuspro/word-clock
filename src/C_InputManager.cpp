#include <C_InputManager.h>
#include <config.h>

C_InputManager::C_InputManager() {}

void C_InputManager::AddButton(ButtonName alias, int ledPin) {
    _buttons[alias].ledPin = ledPin;
    _buttons[alias].isPressed = false;
    _buttons[alias].debouncer.attach(ledPin);
    _buttons[alias].debouncer.interval(DEBOUNCE_INTERVAL);
    Serial.println(_buttons.size());
}

void C_InputManager::Update() {
    for (std::map<ButtonName, ButtonWrapper>::iterator it = _buttons.begin(); it != _buttons.end(); it++) {
        it->second.debouncer.update();
        if (it->second.debouncer.fell()) {
            it->second.isPressed = true;
        }
    }
}

bool C_InputManager::GetKeyDown(ButtonName alias) {
    if (_buttons[alias].isPressed) {
        _buttons[alias].isPressed = false;
        return true;
    }
    return false;
}

void C_InputManager::ClearAllPendingInput(){
    for (std::map<ButtonName, ButtonWrapper>::iterator it = _buttons.begin(); it != _buttons.end(); it++) {
        it->second.isPressed = false;
    }
}