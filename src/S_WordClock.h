#include <Screen.h>
#include <config.h>
#include <bitset>

#ifndef S_WORDCLOCK_H
#define S_WORDCLOCK_H

class S_WordClock : public Screen {
   public:
    void Update();
    void HandleInput();
   private:
    bool _timeSet;
};

#endif