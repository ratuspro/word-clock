#include <Screen.h>

class S_WordClock : public Screen {
   public:
    S_WordClock(class Core* core);
    void Update();

   private:
    void GetTimeFromNTC();
};