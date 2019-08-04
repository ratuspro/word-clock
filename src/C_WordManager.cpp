#include <C_LedManager.h>
#include <C_WordManager.h>
#include <Core.h>
#include <NeoPixelBus.h>
#include <map>
#include <string>
#include <vector>

static const std::vector<LedCoord> LEDS_GAIPS = {
    {6, 0}, {7, 0}, {8, 0}, {9, 0}, {10, 0}};
static const std::vector<LedCoord> LEDS_IT_S = {{0, 0}, {1, 0}, {2, 0}};
static const std::vector<LedCoord> LEDS_TO = {{9, 3}, {10, 3}};
static const std::vector<LedCoord> LEDS_PAST = {{2, 4}, {3, 4}, {4, 4}, {5, 4}};
static const std::vector<LedCoord> LEDS_O_CLOCK = {
    {5, 9},{6, 9}, {7, 9}, {8, 9}, {9, 9}, {10, 9}};
static const std::vector<LedCoord> LEDS_M_A_QUARTER = {
    {2, 1}, {4, 1}, {5, 1}, {6, 1}, {7, 1}, {8, 1}, {9, 1}, {10, 1}};
static const std::vector<LedCoord> LEDS_M_TWENTY = {{0, 2}, {1, 2}, {2, 2},
                                                    {3, 2}, {4, 2}, {5, 2}};
static const std::vector<LedCoord> LEDS_M_FIVE = {
    {7, 2}, {8, 2}, {9, 2}, {10, 2}};
static const std::vector<LedCoord> LEDS_M_HALF = {
    {0, 3}, {1, 3}, {2, 3}, {3, 3}};
static const std::vector<LedCoord> LEDS_M_TEN = {{5, 3}, {6, 3}, {7, 3}};
static const std::vector<LedCoord> LEDS_H_ONE = {{0, 5}, {1, 5}, {2, 5}};
static const std::vector<LedCoord> LEDS_H_TWO = {{8, 6}, {9, 6}, {10, 6}};
static const std::vector<LedCoord> LEDS_H_THREE = {
    {6, 5}, {7, 5}, {8, 5}, {9, 5}, {10, 5}};
static const std::vector<LedCoord> LEDS_H_FOUR = {
    {7, 4}, {8, 4}, {9, 4}, {10, 4}};
static const std::vector<LedCoord> LEDS_H_FIVE = {
    {4, 6}, {5, 6}, {6, 6}, {7, 6}};
static const std::vector<LedCoord> LEDS_H_SIX = {{3, 5}, {4, 5}, {5, 5}};
static const std::vector<LedCoord> LEDS_H_SEVEN = {
    {0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}};
static const std::vector<LedCoord> LEDS_H_EIGHT = {
    {6, 7}, {7, 7}, {8, 7}, {9, 7}, {10, 7}};
static const std::vector<LedCoord> LEDS_H_NINE = {
    {0, 6}, {1, 6}, {2, 6}, {3, 6}};
static const std::vector<LedCoord> LEDS_H_TEN = {{0, 9}, {1, 9}, {2, 9}};
static const std::vector<LedCoord> LEDS_H_ELEVEN = {{0, 7}, {1, 7}, {2, 7},
                                                    {3, 7}, {4, 7}, {5, 7}};
static const std::vector<LedCoord> LEDS_H_TWELVE = {{5, 8}, {6, 8}, {7, 8},
                                                    {8, 8}, {9, 8}, {10, 8}};

std::vector<LedCoord> C_WordManager::GetPixels(C_WordManager::Word word) {
    switch (word) {
        case Word::GAIPS:
            return LEDS_GAIPS;
        case Word::IT_S:
            return LEDS_IT_S;
        case Word::TO:
            return LEDS_TO;
        case Word::PAST:
            return LEDS_PAST;
        case Word::O_CLOCK:
            return LEDS_O_CLOCK;
        case Word::M_A_QUARTER:
            return LEDS_M_A_QUARTER;
        case Word::M_TWENTY:
            return LEDS_M_TWENTY;
        case Word::M_FIVE:
            return LEDS_M_FIVE;
        case Word::M_HALF:
            return LEDS_M_HALF;
        case Word::M_TEN:
            return LEDS_M_TEN;
        case Word::H_ONE:
            return LEDS_H_ONE;
        case Word::H_TWO:
            return LEDS_H_TWO;
        case Word::H_THREE:
            return LEDS_H_THREE;
        case Word::H_FOUR:
            return LEDS_H_FOUR;
        case Word::H_FIVE:
            return LEDS_H_FIVE;
        case Word::H_SIX:
            return LEDS_H_SIX;
        case Word::H_SEVEN:
            return LEDS_H_SEVEN;
        case Word::H_EIGHT:
            return LEDS_H_EIGHT;
        case Word::H_NINE:
            return LEDS_H_NINE;
        case Word::H_TEN:
            return LEDS_H_TEN;
        case Word::H_ELEVEN:
            return LEDS_H_ELEVEN;
        case Word::H_TWELVE:
            return LEDS_H_TWELVE;
        default:
            return {};
    }
}

std::vector<LedCoord> C_WordManager::GetPixels(
    std::vector<C_WordManager::Word> words) {
    std::vector<LedCoord> resultingPixels;
    for (uint8_t i_word = 0; i_word < words.size(); i_word++) {
        std::vector<LedCoord> wordPixels = GetPixels(words[i_word]);
        resultingPixels.insert(resultingPixels.end(), wordPixels.begin(),
                               wordPixels.end());
    }
    return resultingPixels;
}

std::vector<LedCoord> C_WordManager::ConvertHoursToPixels(uint8_t hours,
                                                          bool carry) {
    if (carry) {
        hours++;
    }

    hours = hours %12;
    
    switch (hours) {
        case 0:
            return LEDS_H_TWELVE;
            break;
        case 1:
            return LEDS_H_ONE;
            break;
        case 2:
            return LEDS_H_TWO;
            break;
        case 3:
            return LEDS_H_THREE;
            break;
        case 4:
            return LEDS_H_FOUR;
            break;
        case 5:
            return LEDS_H_FIVE;
            break;
        case 6:
            return LEDS_H_SIX;
            break;
        case 7:
            return LEDS_H_SEVEN;
            break;
        case 8:
            return LEDS_H_EIGHT;
            break;
        case 9:
            return LEDS_H_NINE;
            break;
        case 10:
            return LEDS_H_TEN;
            break;
        case 11:
            return LEDS_H_ELEVEN;
            break;
        default:
            return {};
            break;
    }
}

std::vector<LedCoord> C_WordManager::ConvertMinutesToPixels(uint8_t minutes) {
    std::vector<LedCoord> resultingWords;

    if (minutes >= 0 && minutes < 5) {
        return LEDS_O_CLOCK;
    } else if (minutes >= 5 && minutes < 10) {
        resultingWords = LEDS_M_FIVE;
        resultingWords.insert(resultingWords.end(), LEDS_PAST.begin(),
                              LEDS_PAST.end());
        return resultingWords;
    } else if (minutes >= 10 && minutes < 15) {
        resultingWords = LEDS_M_TEN;
        resultingWords.insert(resultingWords.end(), LEDS_PAST.begin(),
                              LEDS_PAST.end());
        return resultingWords;
    } else if (minutes >= 15 && minutes < 20) {
        resultingWords = LEDS_M_A_QUARTER;
        resultingWords.insert(resultingWords.end(), LEDS_PAST.begin(),
                              LEDS_PAST.end());
        return resultingWords;
    } else if (minutes >= 20 && minutes < 25) {
        resultingWords = LEDS_M_TWENTY;
        resultingWords.insert(resultingWords.end(), LEDS_PAST.begin(),
                              LEDS_PAST.end());
        return resultingWords;
    } else if (minutes >= 25 && minutes < 30) {
        resultingWords = LEDS_M_TWENTY;
        resultingWords.insert(resultingWords.end(), LEDS_M_FIVE.begin(),
                              LEDS_M_FIVE.end());
        resultingWords.insert(resultingWords.end(), LEDS_PAST.begin(),
                              LEDS_PAST.end());
        return resultingWords;
    } else if (minutes >= 30 && minutes < 35) {
        resultingWords = LEDS_M_HALF;
        resultingWords.insert(resultingWords.end(), LEDS_PAST.begin(),
                              LEDS_PAST.end());
        return resultingWords;
    } else if (minutes >= 35 && minutes < 40) {
        resultingWords = LEDS_M_TWENTY;
        resultingWords.insert(resultingWords.end(), LEDS_M_FIVE.begin(),
                              LEDS_M_FIVE.end());
        resultingWords.insert(resultingWords.end(), LEDS_TO.begin(),
                              LEDS_TO.end());
        return resultingWords;
    } else if (minutes >= 40 && minutes < 45) {
        resultingWords = LEDS_M_TWENTY;
        resultingWords.insert(resultingWords.end(), LEDS_TO.begin(),
                              LEDS_TO.end());
        return resultingWords;
    } else if (minutes >= 45 && minutes < 50) {
        resultingWords = LEDS_M_A_QUARTER;
        resultingWords.insert(resultingWords.end(), LEDS_TO.begin(),
                              LEDS_TO.end());
        return resultingWords;
    } else if (minutes >= 50 && minutes < 55) {
        resultingWords = LEDS_M_TEN;
        resultingWords.insert(resultingWords.end(), LEDS_TO.begin(),
                              LEDS_TO.end());
        return resultingWords;
    } else if (minutes >= 55 && minutes < 60) {
        resultingWords = LEDS_M_FIVE;
        resultingWords.insert(resultingWords.end(), LEDS_TO.begin(),
                              LEDS_TO.end());
        return resultingWords;
    }

    return resultingWords;
}

std::vector<LedCoord> C_WordManager::ConvertTimeToPixels(uint8_t hours,
                                                         uint8_t minutes) {
    std::vector<LedCoord> pixels;
    std::vector<LedCoord> auxiliary;

    auxiliary = GetPixels(Word::IT_S);
    pixels.insert(pixels.end(), auxiliary.begin(), auxiliary.end());

    auxiliary = ConvertHoursToPixels(hours, minutes > 30);
    pixels.insert(pixels.end(), auxiliary.begin(), auxiliary.end());

    auxiliary = ConvertMinutesToPixels(minutes);
    pixels.insert(pixels.end(), auxiliary.begin(), auxiliary.end());

    return pixels;
}
