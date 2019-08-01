#include <Component.h>
#include <bitset>
#include <vector>
#include <config.h>
#include <string>
#include <C_LedManager.h>

#ifndef C_WordManager_H
#define C_WordManager_H

class C_WordManager : Component {
   public:
    enum Word {
        IT_S,
        GAIPS,
        TO,
        PAST,
        O_CLOCK,
        M_A_QUARTER,
        M_TWENTY,
        M_FIVE,
        M_HALF,
        M_TEN,
        H_ONE,
        H_TWO,
        H_THREE,
        H_FOUR,
        H_FIVE,
        H_SIX,
        H_SEVEN,
        H_EIGHT,
        H_NINE,
        H_TEN,
        H_ELEVEN,
        H_TWELVE,
    };
    C_WordManager();
    std::vector<LedCoord> GetPixels(Word word);
    std::vector<LedCoord> GetPixels(std::vector<C_WordManager::Word> words);
    std::vector<LedCoord> ConvertTimeToPixels(uint8_t hours, uint8_t minutes);
    std::vector<LedCoord> ConvertHoursToPixels(uint8_t hours, bool carry);
    std::vector<LedCoord> ConvertMinutesToPixels(uint8_t minutes);
};

#endif