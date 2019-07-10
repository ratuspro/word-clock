#include <Core.h>
#include <S_WordClock.h>
#include <config.h>
#include "time.h"

RgbColor red(255, 0, 0);
RgbColor black(0, 0, 0);

S_WordClock::S_WordClock(Core* owner) : Screen(owner) { _timeSet = false; }

void S_WordClock::Update() {
    if (_currentState == Screen::State::RUNNING) {
        if (!_timeSet) {
            configTime(TIME_GMT_OFFSET, TIME_DAYLIGHT_OFFSET, TIME_NTP_SERVER);
            _timeSet = true;
        } else {
            struct tm timeinfo;
            if (!getLocalTime(&timeinfo)) {
                Serial.println("Failed to obtain time");
                _timeSet = false;
                return;
            } else {
                _owner->_ledManager->ClearPixels(black);
                _owner->_ledManager->SetPixels(ConvertTimeToLeds(timeinfo),
                                               red);
            }
        }
    }
}

std::bitset<NUM_LEDS> S_WordClock::ConvertTimeToLeds(struct tm time) {
    std::vector<WordMapping::Word> words;

    words.push_back(WordMapping::IT_S);

    int hour = time.tm_hour % 12;
    switch (hour) {
        case 0:
            words.push_back(WordMapping::H_TWELVE);
            break;
        case 1:
            words.push_back(WordMapping::H_ONE);
            break;
        case 2:
            words.push_back(WordMapping::H_TWO);
            break;
        case 3:
            words.push_back(WordMapping::H_THREE);
            break;
        case 4:
            words.push_back(WordMapping::H_FOUR);
            break;
        case 5:
            words.push_back(WordMapping::H_FIVE);
            break;
        case 6:
            words.push_back(WordMapping::H_SIX);
            break;
        case 7:
            words.push_back(WordMapping::H_SEVEN);
            break;
        case 8:
            words.push_back(WordMapping::H_EIGHT);
            break;
        case 9:
            words.push_back(WordMapping::H_NINE);
            break;
        case 10:
            words.push_back(WordMapping::H_TEN);
            break;
        case 11:
            words.push_back(WordMapping::H_ELEVEN);
            break;
        default:
            break;
    }

    // Minutes
    if (time.tm_min >= 0 && time.tm_min < 5) {
        words.push_back(WordMapping::O_CLOCK);
    } else if (time.tm_min >= 5 && time.tm_min < 10) {
        words.push_back(WordMapping::M_FIVE);
        words.push_back(WordMapping::PAST);
    } else if (time.tm_min >= 10 && time.tm_min < 15) {
        words.push_back(WordMapping::M_TEN);
        words.push_back(WordMapping::PAST);
    } else if (time.tm_min >= 15 && time.tm_min < 20) {
        words.push_back(WordMapping::M_A_QUARTER);
        words.push_back(WordMapping::PAST);
    } else if (time.tm_min >= 20 && time.tm_min < 25) {
        words.push_back(WordMapping::M_TWENTY);
        words.push_back(WordMapping::PAST);
    } else if (time.tm_min >= 25 && time.tm_min < 30) {
        words.push_back(WordMapping::M_TWENTY);
        words.push_back(WordMapping::M_FIVE);
        words.push_back(WordMapping::PAST);
    } else if (time.tm_min >= 30 && time.tm_min < 35) {
        words.push_back(WordMapping::M_HALF);
        words.push_back(WordMapping::PAST);
    } else if (time.tm_min >= 35 && time.tm_min < 40) {
        words.push_back(WordMapping::M_TWENTY);
        words.push_back(WordMapping::M_FIVE);
        words.push_back(WordMapping::TO);
    } else if (time.tm_min >= 40 && time.tm_min < 45) {
        words.push_back(WordMapping::M_TWENTY);
        words.push_back(WordMapping::TO);
    } else if (time.tm_min >= 45 && time.tm_min < 50) {
        words.push_back(WordMapping::M_A_QUARTER);
        words.push_back(WordMapping::TO);
    } else if (time.tm_min >= 50 && time.tm_min < 55) {
        words.push_back(WordMapping::M_TEN);
        words.push_back(WordMapping::TO);
    } else if (time.tm_min >= 55 && time.tm_min < 60) {
        words.push_back(WordMapping::M_FIVE);
        words.push_back(WordMapping::TO);
    }

    std::bitset<NUM_LEDS> leds;
    // Convert words to leds
    for (WordMapping::Word word : words) {
        leds |= _owner->_wordMapping->GetLeds(word);
    }

    return leds;
}
