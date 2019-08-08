#include <Screen.h>
#include <string>
#include <memory>
#include <vector>
#include <Screen_Menu.h>

#ifndef S_MENU_H
#define S_MENU_H

class S_Menu : public Screen {
    struct MenuEntry {
        std::string iconName;
        std::shared_ptr<Screen_Menu> screen;
    };

   public:
    S_Menu();
    void Update();
    bool _inSubMenu;
   private:
    uint8_t _selectedEntry;
    std::vector<MenuEntry> _entries;
    void addEntry(std::string iconName,std::shared_ptr<Screen_Menu> screen);
    void HandleInput();
    void DrawSidebar();
    void DrawIcon();
};

#endif
