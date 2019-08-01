#include <C_EepromManager.h>
#include <config.h>
#include <EEPROM.h>

RgbColor C_EepromManager::GetForegroundColor() {
    return RgbColor(EEPROM.readUInt(EEPROM_ADDRESS_COLOR_R),EEPROM.readUInt(EEPROM_ADDRESS_COLOR_G),EEPROM.readUInt(EEPROM_ADDRESS_COLOR_B));
}