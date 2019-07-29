#include <C_IconManager.h>

C_IconManager::C_IconManager() {
}

Icon C_IconManager::GetFrame(std::string iconName, float progress) {
    return _icons[iconName];
}