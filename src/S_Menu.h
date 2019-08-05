#include <Screen.h>
#include <string>
#include <memory>
#include <vector>

class S_Menu : public Screen {
    struct MenuEntry {
        std::string iconName;
        std::shared_ptr<Screen> screen;
    };

   public:
    S_Menu();
    void Update();
   private:
    uint8_t _selectedEntry;
    bool _inSubMenu;
    std::vector<MenuEntry> _entries;
    void addEntry(std::string iconName,std::shared_ptr<Screen> screen);
    void HandleInput();
    void DrawSidebar();
    void DrawIcon();
};