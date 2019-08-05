#include <C_IconManager.h>
#include <vector>

static std::vector<std::vector<bool>> _wifi = {
    {1, 1, 1, 0, 0, 0, 0, 0}, 
    {1, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0}, 
    {1, 1, 1, 0, 1, 1, 0, 0},
    {1, 1, 1, 1, 0, 1, 1, 0}, 
    {0, 0, 0, 1, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 0, 1, 1}, 
    {1, 1, 0, 1, 1, 0, 1, 1}};

static std::vector<std::vector<bool>> _brightness = {
    {0, 1, 1, 1, 1, 1, 1, 0}, 
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 1, 0}, 
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0}, 
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0}, 
    {0, 0, 0, 1, 1, 0, 0, 0}};

static std::vector<std::vector<bool>> _time = {
    {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};

static std::vector<std::vector<bool>> _color = {
    {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0}};

C_IconManager::C_IconManager() {
    Icon iconWifi;
    iconWifi._frame = _wifi;
    _icons["time"] = iconWifi;

    Icon brightnessColor;
    brightnessColor._frame = _brightness;
    _icons["brightness"] = brightnessColor;
}

Icon C_IconManager::GetFrame(std::string iconName) { return _icons[iconName]; }