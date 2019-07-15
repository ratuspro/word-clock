#include <Screen.h>
#include <time.h>
class S_NetworkingConnectionScreen : public Screen {
   public:
    void Update();

   private:
    bool TryConnection();
    int _attempts = 1;
    clock_t _lastAttempt = clock();
};