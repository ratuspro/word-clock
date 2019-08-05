#include <C_EepromManager.h>
#include <config.h>
#include <EEPROM.h>

RgbColor C_EepromManager::GetForegroundColor() {
    return RgbColor(EEPROM.readUInt(EEPROM_ADDRESS_COLOR_R),EEPROM.readUInt(EEPROM_ADDRESS_COLOR_G),EEPROM.readUInt(EEPROM_ADDRESS_COLOR_B));
}

void C_EepromManager::SetForegroundColor(RgbColor color) {
    EEPROM.writeUInt(EEPROM_ADDRESS_COLOR_R,color.R);
    EEPROM.writeUInt(EEPROM_ADDRESS_COLOR_G,color.G);
    EEPROM.writeUInt(EEPROM_ADDRESS_COLOR_B,color.B);
    EEPROM.commit();
}

uint8_t C_EepromManager::GetBrightness() {
    return EEPROM.readUInt(EEPROM_ADDRESS_BRIGTHNESS);
}

void C_EepromManager::SetBrightness(uint8_t value) {
    EEPROM.writeUInt(EEPROM_ADDRESS_BRIGTHNESS,value);
    EEPROM.commit();
}