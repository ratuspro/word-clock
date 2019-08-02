#include <Screen.h>
#include <config.h>
#include <bitset>

class S_WordClock : public Screen {
   public:
    void Update();
    void HandleInput();
   private:
    bool _timeSet;
};