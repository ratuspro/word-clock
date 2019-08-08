#include <Component.h>

#ifndef C_NETWORKMANAGER_H
#define C_NETWORKMANAGER_H

class C_NetworkManager : public Component{
    public:
        void SetupConnection();
        bool IsConnected();
};

#endif