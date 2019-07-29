#include <Component.h>
#include <map>
#include <Bounce2.h>

class C_InputManager : public Component {
    struct ButtonWrapper {
        uint8_t ledPin;
        bool isPressed;
        Bounce debouncer;
    };

   public:
    enum ButtonName { UP, DOWN, CONFIRM, MENU };
    C_InputManager();
    void AddButton(ButtonName alias, int buttonID);
    void Update();
    bool GetKeyDown(ButtonName alias);

   private:
    std::map<ButtonName, ButtonWrapper> _buttons;
};