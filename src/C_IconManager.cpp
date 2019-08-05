#include <C_IconManager.h>
#include <vector>

void C_IconManager::AddIcon(std::string iconName, Icon icon) {
    _icons[iconName] = icon;
}
Icon C_IconManager::GetIcon(std::string iconName) {
    return _icons[iconName];
}