#include <Screen_Menu.h>
#include <Core.h>

void  Screen_Menu::ExitScreen(){
    CurrentStage = ICON;
    Core::getInstance()->_menu->_inSubMenu = false;
}