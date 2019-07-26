#include <Core.h>
#include <S_WordClock.h>
#include <WiFi.h>
#include <config.h>
#include <time.h>

RgbColor black(0, 0, 0);

void S_WordClock::Update() {
    if (_currentState == Screen::State::RUNNING) {
        struct tm now;
        getLocalTime(&now, 0);
        Core::getInstance()->_ledManager->ClearPixels(black);
        std::bitset<NUM_LEDS> currentTimeLeds =
            S_WordClock::ConvertTimeToLeds(now.tm_hour, now.tm_min);
        Core::getInstance()->_ledManager->SetPixels(
            currentTimeLeds,
            *Core::getInstance()->_ledManager->GetColorFromEEPROM());
    }
}

std::bitset<NUM_LEDS> S_WordClock::ConvertTimeToLeds(int hours, int minutes) {
    std::vector<WordMapping::Word> words;

    words.push_back(WordMapping::IT_S);

    if (minutes > 30) {
        hours++;
    }
    int hour = hours % 12;
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
    if (minutes >= 0 && minutes < 5) {
        words.push_back(WordMapping::O_CLOCK);
    } else if (minutes >= 5 && minutes < 10) {
        words.push_back(WordMapping::M_FIVE);
        words.push_back(WordMapping::PAST);
    } else if (minutes >= 10 && minutes < 15) {
        words.push_back(WordMapping::M_TEN);
        words.push_back(WordMapping::PAST);
    } else if (minutes >= 15 && minutes < 20) {
        words.push_back(WordMapping::M_A_QUARTER);
        words.push_back(WordMapping::PAST);
    } else if (minutes >= 20 && minutes < 25) {
        words.push_back(WordMapping::M_TWENTY);
        words.push_back(WordMapping::PAST);
    } else if (minutes >= 25 && minutes < 30) {
        words.push_back(WordMapping::M_TWENTY);
        words.push_back(WordMapping::M_FIVE);
        words.push_back(WordMapping::PAST);
    } else if (minutes >= 30 && minutes < 35) {
        words.push_back(WordMapping::M_HALF);
        words.push_back(WordMapping::PAST);
    } else if (minutes >= 35 && minutes < 40) {
        words.push_back(WordMapping::M_TWENTY);
        words.push_back(WordMapping::M_FIVE);
        words.push_back(WordMapping::TO);
    } else if (minutes >= 40 && minutes < 45) {
        words.push_back(WordMapping::M_TWENTY);
        words.push_back(WordMapping::TO);
    } else if (minutes >= 45 && minutes < 50) {
        words.push_back(WordMapping::M_A_QUARTER);
        words.push_back(WordMapping::TO);
    } else if (minutes >= 50 && minutes < 55) {
        words.push_back(WordMapping::M_TEN);
        words.push_back(WordMapping::TO);
    } else if (minutes >= 55 && minutes < 60) {
        words.push_back(WordMapping::M_FIVE);
        words.push_back(WordMapping::TO);
    }

    std::bitset<NUM_LEDS> leds;
    // Convert words to leds
    for (WordMapping::Word word : words) {
        leds |= Core::getInstance()->_wordMapping->GetLeds(word);
    }

    return leds;
}
