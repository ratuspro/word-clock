#include <Component.h>
#include <vector>
#include <map>
#include <Icon.h>
#include <string>

class C_IconManager : public Component{
    public:
        C_IconManager();
        Icon GetFrame(std::string iconName, float progress);
    private:
        std::map<std::string, Icon> _icons;
};