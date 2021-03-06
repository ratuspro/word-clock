#include <Component.h>

#ifndef SCREEN_H
#define SCREEN_H

class Screen : Component {
   public:
    enum State { RUNNING, STOPPED };
    Screen();
    virtual void Update() = 0;
    void Stop();
    void Run();
    State _currentState;
};
#endif