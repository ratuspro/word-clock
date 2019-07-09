#include <Core.h>
#include <Screen.h>

Screen::Screen(Core* core) : Component(core) {
    _currentState = State::STOPPED;
}

void Screen::Enter() {
    _currentState = State::ENTERING;
}

void Screen::Run() {
    _currentState = State::RUNNING;
}

void Screen::Exit() {
    _currentState = State::EXITING;
}

void Screen::Stop() {
    _currentState = State::STOPPED;
}