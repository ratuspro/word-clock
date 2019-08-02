#include <C_LedManager.h>
#include <vector>

#ifndef ICON_H
#define ICON_H

class Icon {
   public:
    std::vector<std::vector<bool>> _frame;
    std::vector<LedCoord> GetPixelsCoordinates();
};

#endif