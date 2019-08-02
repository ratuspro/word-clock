#include <Icon.h>

std::vector<LedCoord> Icon::GetPixelsCoordinates() {
    std::vector<LedCoord> coordinates;
    for (uint8_t y = 0; y < _frame.size(); y++) {
        for (uint8_t x = 0; x < _frame[y].size(); x++) {
            if (_frame[y][x]) {
                coordinates.push_back(LedCoord({x, y}));
            }
        }
    }

    return coordinates;
}