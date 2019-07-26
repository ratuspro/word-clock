#include <Component.h>

class C_NetworkManager : public Component{
    public:
        void SetupConnection();
        bool IsConnected();
};