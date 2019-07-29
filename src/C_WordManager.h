#include <Component.h>
#include <bitset>
#include <vector>
#include <config.h>
#include <string>

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
    std::bitset<NUM_LEDS> GetLeds(C_WordManager::Word word);
    std::bitset<NUM_LEDS> GetLeds(uint_fast8_t number);
    std::vector<std::vector<bool>> GetPixelsForLetter(char letter);
    std::vector<std::vector<bool>> GetPixelsForText(std::string text);
};

#endif