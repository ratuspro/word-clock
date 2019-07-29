#include <C_WordManager.h>
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

C_WordManager::C_WordManager() : Component() {}

std::bitset<NUM_LEDS> C_WordManager::GetLeds(uint_fast8_t number) {
    switch (number) {
        case 1:
            return C_WordManager::GetLeds(Word::H_ONE);
        case 2:
            return C_WordManager::GetLeds(Word::H_TWO);
        case 3:
            return C_WordManager::GetLeds(Word::H_THREE);
        case 4:
            return C_WordManager::GetLeds(Word::H_FOUR);
        case 5:
            return C_WordManager::GetLeds(Word::H_FIVE);
        case 6:
            return C_WordManager::GetLeds(Word::H_SIX);
        case 7:
            return C_WordManager::GetLeds(Word::H_SEVEN);
        case 8:
            return C_WordManager::GetLeds(Word::H_EIGHT);
        case 9:
            return C_WordManager::GetLeds(Word::H_NINE);
        case 10:
            return C_WordManager::GetLeds(Word::H_TEN);
        case 11:
            return C_WordManager::GetLeds(Word::H_ELEVEN);
        case 12:
            return C_WordManager::GetLeds(Word::H_TWELVE);
        default:
            return std::bitset<NUM_LEDS>();
    }
}

std::bitset<NUM_LEDS> C_WordManager::GetLeds(C_WordManager::Word word) {
    switch (word) {
        case C_WordManager::Word::GAIPS:
            return std::bitset<NUM_LEDS>(LEDS_GAIPS);
        case C_WordManager::Word::IT_S:
            return std::bitset<NUM_LEDS>(LEDS_IT_S);
        case C_WordManager::Word::TO:
            return std::bitset<NUM_LEDS>(LEDS_TO);
        case C_WordManager::Word::PAST:
            return std::bitset<NUM_LEDS>(LEDS_PAST);
        case C_WordManager::Word::O_CLOCK:
            return std::bitset<NUM_LEDS>(LEDS_O_CLOCK);
        case C_WordManager::Word::M_A_QUARTER:
            return std::bitset<NUM_LEDS>(LEDS_M_A_QUARTER);
        case C_WordManager::Word::M_TWENTY:
            return std::bitset<NUM_LEDS>(LEDS_M_TWENTY);
        case C_WordManager::Word::M_FIVE:
            return std::bitset<NUM_LEDS>(LEDS_M_FIVE);
        case C_WordManager::Word::M_HALF:
            return std::bitset<NUM_LEDS>(LEDS_M_HALF);
        case C_WordManager::Word::M_TEN:
            return std::bitset<NUM_LEDS>(LEDS_M_TEN);
        case C_WordManager::Word::H_ONE:
            return std::bitset<NUM_LEDS>(LEDS_H_ONE);
        case C_WordManager::Word::H_TWO:
            return std::bitset<NUM_LEDS>(LEDS_H_TWO);
        case C_WordManager::Word::H_THREE:
            return std::bitset<NUM_LEDS>(LEDS_H_THREE);
        case C_WordManager::Word::H_FOUR:
            return std::bitset<NUM_LEDS>(LEDS_H_FOUR);
        case C_WordManager::Word::H_FIVE:
            return std::bitset<NUM_LEDS>(LEDS_H_FIVE);
        case C_WordManager::Word::H_SIX:
            return std::bitset<NUM_LEDS>(LEDS_H_SIX);
        case C_WordManager::Word::H_SEVEN:
            return std::bitset<NUM_LEDS>(LEDS_H_SEVEN);
        case C_WordManager::Word::H_EIGHT:
            return std::bitset<NUM_LEDS>(LEDS_H_EIGHT);
        case C_WordManager::Word::H_NINE:
            return std::bitset<NUM_LEDS>(LEDS_H_NINE);
        case C_WordManager::Word::H_TEN:
            return std::bitset<NUM_LEDS>(LEDS_H_TEN);
        case C_WordManager::Word::H_ELEVEN:
            return std::bitset<NUM_LEDS>(LEDS_H_ELEVEN);
        case C_WordManager::Word::H_TWELVE:
            return std::bitset<NUM_LEDS>(LEDS_H_TWELVE);
        default:
            return std::bitset<NUM_LEDS>(0);
    }
}

std::vector<std::vector<bool>> C_WordManager::GetPixelsForLetter(char letter){

}

std::vector<std::vector<bool>> C_WordManager::GetPixelsForText(std::string text){

    std::vector<std::vector<bool>> textInPixels;

    //Create Word Pixels
    uint8_t currentLetter = 0;
    uint8_t currentX = 0;
    
    //For each letter on the text, copy it to word pixels
    for (std::string::iterator it = text.begin(); it != text.end(); it++) {
        std::vector<std::vector<bool>> letter = GetPixelsForLetter(*it);
        for (uint8_t x = currentX; x < letter.size(); x++){
            textInPixels[x].resize(letter[x].size());
            for (uint8_t y = 0; y < letter[x].size(); y++){
                textInPixels[x][y] = letter[x][y]; 
            }
        }
        currentX = currentX + LETTER_WIDTH + LETTER_SPACING;
    }

    return textInPixels;
}