#include <Screen.h>

#ifndef SCREEN_MENU_H
#define SCREEN_MENU_H

class Screen_Menu : public Screen{
    public:  
        enum MENU_STAGE { ICON, IN_CONFIGURATION};
        MENU_STAGE CurrentStage;
        Screen_Menu(MENU_STAGE newStage) : CurrentStage(newStage) {};
};

#endif