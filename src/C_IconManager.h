#include <Component.h>
#include <vector>
#include <map>
#include <Icon.h>
#include <string>

class C_IconManager : public Component{
    public:
        void AddIcon(std::string iconName, Icon icon);
        Icon GetIcon(std::string iconName);
    private:
        std::map<std::string, Icon> _icons;
};