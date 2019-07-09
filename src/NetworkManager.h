#include <Component.h>
#include <WiFi.h>

#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

class NetworkManager : Component {
   public:
    NetworkManager(class Core* core);
    void Setup();
};

#endif