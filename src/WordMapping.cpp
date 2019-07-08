#include <NeoPixelBus.h>
#include <WordMapping.h>
#include <map>
#include <vector>

std::map<WordMapping::Word, std::vector<int>> _pixelMap;

std::vector<int> WordMapping::GetLeds(WordMapping::Word word) {
    return WordMapping::GetLeds(std::bitset<110>(word));
}

std::vector<int> WordMapping::GetLeds(std::bitset<110> ledBitMask) {
    std::vector<int> pixels;
    for (int i = 0; i < 110; i++) {
        if (ledBitMask[i] == 1) {
            pixels.push_back(i);
        }
    }
    return pixels;
}