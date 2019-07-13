#include <Core.h>
#include <Screen.h>

Screen::Screen() : Component() {
    _currentState = State::STOPPED;
}

void Screen::Run() {
    _currentState = State::RUNNING;
}

void Screen::Stop() {
    _currentState = State::STOPPED;
}