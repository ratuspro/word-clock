#include <WordMapping.h>
#include <map>
#include <vector>

std::map<WordMapping::Word, std::vector<int>> _pixelMap;

WordMapping::WordMapping() {
    std::vector<int> pixels;
    pixels = std::vector<int>{8,9,29};
    _pixelMap.insert(
        std::pair<WordMapping::Word, std::vector<int>>(Word::IT_S, pixels));

    pixels = std::vector<int>{60,79,80,99,100};
    _pixelMap.insert(
        std::pair<WordMapping::Word, std::vector<int>>(Word::GAIPS, pixels));

}

std::vector<int> WordMapping::GetPixel(WordMapping::Word word) {
    if(_pixelMap.find(word) != _pixelMap.end()){
        return _pixelMap[word];
    }
    return std::vector<int>();
}