#include <C_LedManager.h>
#include <C_WordMapping.h>
#include <Core.h>
#include <S_StartingScreen.h>
#include <S_NetworkingConnectionScreen.h>

S_StartingScreen::S_StartingScreen() {
    _numberOfFades = 5;
    _progress = 0;
    _increasing = true;
    _initialColor = new RgbColor(0, 0, 0);
    _targetColor = new RgbColor(0, 0, 255);
}

void S_StartingScreen::Update() {
    if (_word.count() == 0) {
        _word = Core::getInstance()->_wordMapping->GetLeds(WordMapping::GAIPS);
    }

    Core::getInstance()->_ledManager->SetPixels(
        _word,
        _targetColor->LinearBlend(*_initialColor, *_targetColor, _progress));

    if (_increasing) {
        _progress += 0.01;
        if (_progress > 1) {
            _progress = 1;
            _increasing = false;
        }
    } else {
        _progress -= 0.01;
        if (_progress < 0) {
            _progress = 0;
            _increasing = true;
            _numberOfFades--;
        }
    }

    if(_numberOfFades <=0 ){
        Core::getInstance()->MoveToScreen(std::make_shared<S_NetworkingConnectionScreen>());
    }
}