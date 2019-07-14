#include <Component.h>
#include <bitset>
#include <vector>

#ifndef WORDMAPPING_H
#define WORDMAPPING_H

class WordMapping : Component {
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
    WordMapping();
    std::bitset<110> GetLeds(WordMapping::Word word);
};

#endif