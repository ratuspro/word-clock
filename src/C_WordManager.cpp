#include <C_LedManager.h>
#include <C_WordManager.h>
#include <Core.h>
#include <NeoPixelBus.h>
#include <map>
#include <string>
#include <vector>

static const std::vector<LedCoord> LEDS_GAIPS = {{1, 0}, {0, 2}};

C_WordManager::C_WordManager() : Component() {}

std::vector<LedCoord> C_WordManager::GetPixels(C_WordManager::Word word) {
    std::vector<LedCoord> resultingPixels;

    // TODO: Add Logic here

    return resultingPixels;
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
                                                          bool carry) {}

std::vector<LedCoord> C_WordManager::ConvertMinutesToPixels(uint8_t minutes) {}

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
