#include <Component.h>
#ifndef SCREEN_H
#define SCREEN_H
class Screen : Component {
   public:
    enum State { ENTERING,
                 EXITING,
                 RUNNING,
                 STOPPED };
    Screen(class Core* core);
    virtual void Update() = 0;
    void Stop();
    void Enter();
    void Run();
    void Exit();

   protected:
    State _currentState;
};
#endif