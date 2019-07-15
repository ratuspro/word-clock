#include <C_WordMapping.h>
#include <Core.h>
#include <NeoPixelBus.h>
#include <map>
#include <string>
#include <vector>

static const std::string LEDS_GAIPS =
    "10000000000000000001100000000000000000011000000000000000000000000000000000"
    "000000000000000000000000000000000000";
static const std::string LEDS_IT_S =
    "00000000000000000000000000000000000000000000000000000000000000000000000000"
    "000000100000000000000000011000000000";
static const std::string LEDS_TO =
    "00010000000000001000000000000000000000000000000000000000000000000000000000"
    "000000000000000000000000000000000000";
static const std::string LEDS_PAST =
    "00000000000000000000000000000000000000000000000000000001000000001000000000"
    "010000000010000000000000000000000000";
static const std::string LEDS_O_CLOCK =
    "00000000011000000000000000000110000000000000000001100000000000000000000000"
    "000000000000000000000000000000000000";
static const std::string LEDS_M_A_QUARTER =
    "01000000000000000010010000000000000000100100000000000000001001000000000000"
    "000000010000000000000000000000000000";
static const std::string LEDS_M_TWENTY =
    "00000000000000000000000000000000000000000000000000000000010000100000000000"
    "000100001000000000000001000010000000";
static const std::string LEDS_M_FIVE =
    "00100000000000000100001000000000000001000000000000000000000000000000000000"
    "000000000000000000000000000000000000";
static const std::string LEDS_M_HALF =
    "00000000000000000000000000000000000000000000000000000000000000000000000000"
    "001000000100000000000010000001000000";
static const std::string LEDS_M_TEN =
    "00000000000000000000000000000000000010000001000000000000100000000000000000"
    "000000000000000000000000000000000000";
static const std::string LEDS_H_ONE =
    "00000000000000000000000000000000000000000000000000000000000000000000000000"
    "000000000001000000001000000000010000";
static const std::string LEDS_H_TWO =
    "00000010000001000000000000100000000000000000000000000000000000000000000000"
    "000000000000000000000000000000000000";
static const std::string LEDS_H_THREE =
    "00000100000000100000000001000000001000000000010000000000000000000000000000"
    "000000000000000000000000000000000000";
static const std::string LEDS_H_FOUR =
    "00001000000000010000000010000000000100000000000000000000000000000000000000"
    "000000000000000000000000000000000000";
static const std::string LEDS_H_FIVE =
    "00000000000000000000000000000000010000000000001000000100000000000010000000"
    "000000000000000000000000000000000000";
static const std::string LEDS_H_SIX =
    "00000000000000000000000000000000000000000000000000000010000000000100000000"
    "100000000000000000000000000000000000";
static const std::string LEDS_H_SEVEN =
    "00000000000000000000000000000000000000000000000000000000000000000000100100"
    "000000000000001001000000000000000010";
static const std::string LEDS_H_EIGHT =
    "00000001000010000000000000010000100000000000000100000000000000000000000000"
    "000000000000000000000000000000000000";
static const std::string LEDS_H_NINE =
    "00000000000000000000000000000000000000000000000000000000000000000000000001"
    "000000000000100000010000000000001000";
static const std::string LEDS_H_TEN =
    "00000000000000000000000000000000000000000000000000000000000000000000000000"
    "000000000000000110000000000000000001";
static const std::string LEDS_H_ELEVEN =
    "00000000000000000000000000000000000000000000000000001000000000000001000010"
    "000000000000010000100000000000000100";
static const std::string LEDS_H_TWELVE =
    "00000000100100000000000000001001000000000000000010010000000000000000000000"
    "000000000000000000000000000000000000";

WordMapping::WordMapping() : Component() {}

std::bitset<NUM_LEDS> WordMapping::GetLeds(uint_fast8_t number) {
    switch (number) {
        case 1:
            return WordMapping::GetLeds(Word::H_ONE);
        case 2:
            return WordMapping::GetLeds(Word::H_TWO);
        case 3:
            return WordMapping::GetLeds(Word::H_THREE);
        case 4:
            return WordMapping::GetLeds(Word::H_FOUR);
        case 5:
            return WordMapping::GetLeds(Word::H_FIVE);
        case 6:
            return WordMapping::GetLeds(Word::H_SIX);
        case 7:
            return WordMapping::GetLeds(Word::H_SEVEN);
        case 8:
            return WordMapping::GetLeds(Word::H_EIGHT);
        case 9:
            return WordMapping::GetLeds(Word::H_NINE);
        case 10:
            return WordMapping::GetLeds(Word::H_TEN);
        case 11:
            return WordMapping::GetLeds(Word::H_ELEVEN);
        case 12:
            return WordMapping::GetLeds(Word::H_TWELVE);
        default:
            return std::bitset<NUM_LEDS>();
    }
}

std::bitset<NUM_LEDS> WordMapping::GetLeds(WordMapping::Word word) {
    switch (word) {
        case WordMapping::Word::GAIPS:
            return std::bitset<NUM_LEDS>(LEDS_GAIPS);
        case WordMapping::Word::IT_S:
            return std::bitset<NUM_LEDS>(LEDS_IT_S);
        case WordMapping::Word::TO:
            return std::bitset<NUM_LEDS>(LEDS_TO);
        case WordMapping::Word::PAST:
            return std::bitset<NUM_LEDS>(LEDS_PAST);
        case WordMapping::Word::O_CLOCK:
            return std::bitset<NUM_LEDS>(LEDS_O_CLOCK);
        case WordMapping::Word::M_A_QUARTER:
            return std::bitset<NUM_LEDS>(LEDS_M_A_QUARTER);
        case WordMapping::Word::M_TWENTY:
            return std::bitset<NUM_LEDS>(LEDS_M_TWENTY);
        case WordMapping::Word::M_FIVE:
            return std::bitset<NUM_LEDS>(LEDS_M_FIVE);
        case WordMapping::Word::M_HALF:
            return std::bitset<NUM_LEDS>(LEDS_M_HALF);
        case WordMapping::Word::M_TEN:
            return std::bitset<NUM_LEDS>(LEDS_M_TEN);
        case WordMapping::Word::H_ONE:
            return std::bitset<NUM_LEDS>(LEDS_H_ONE);
        case WordMapping::Word::H_TWO:
            return std::bitset<NUM_LEDS>(LEDS_H_TWO);
        case WordMapping::Word::H_THREE:
            return std::bitset<NUM_LEDS>(LEDS_H_THREE);
        case WordMapping::Word::H_FOUR:
            return std::bitset<NUM_LEDS>(LEDS_H_FOUR);
        case WordMapping::Word::H_FIVE:
            return std::bitset<NUM_LEDS>(LEDS_H_FIVE);
        case WordMapping::Word::H_SIX:
            return std::bitset<NUM_LEDS>(LEDS_H_SIX);
        case WordMapping::Word::H_SEVEN:
            return std::bitset<NUM_LEDS>(LEDS_H_SEVEN);
        case WordMapping::Word::H_EIGHT:
            return std::bitset<NUM_LEDS>(LEDS_H_EIGHT);
        case WordMapping::Word::H_NINE:
            return std::bitset<NUM_LEDS>(LEDS_H_NINE);
        case WordMapping::Word::H_TEN:
            return std::bitset<NUM_LEDS>(LEDS_H_TEN);
        case WordMapping::Word::H_ELEVEN:
            return std::bitset<NUM_LEDS>(LEDS_H_ELEVEN);
        case WordMapping::Word::H_TWELVE:
            return std::bitset<NUM_LEDS>(LEDS_H_TWELVE);
        default:
            return std::bitset<NUM_LEDS>(0);
    }
}