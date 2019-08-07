#include <C_EepromManager.h>
#include <config.h>
#include <EEPROM.h>
#include <string>

C_EepromManager::C_EepromManager(){
    PrintAll();
}

RgbColor C_EepromManager::GetForegroundColor() {
    return RgbColor(EEPROM.readByte(EEPROM_ADDRESS_COLOR_R),EEPROM.readByte(EEPROM_ADDRESS_COLOR_G),EEPROM.readByte(EEPROM_ADDRESS_COLOR_B));
}

void C_EepromManager::SetForegroundColor(RgbColor color) {
    EEPROM.writeByte(EEPROM_ADDRESS_COLOR_R,color.R);
    EEPROM.writeByte(EEPROM_ADDRESS_COLOR_G,color.G);
    EEPROM.writeByte(EEPROM_ADDRESS_COLOR_B,color.B);
    EEPROM.commit();
    Serial.println("Changed EEPROM:");
    PrintAll();
}

uint8_t C_EepromManager::GetBrightness() {
    return EEPROM.readByte(EEPROM_ADDRESS_BRIGTHNESS);
}

void C_EepromManager::SetBrightness(uint8_t value) {
    EEPROM.writeByte(EEPROM_ADDRESS_BRIGTHNESS,value);
    EEPROM.commit();
    Serial.println("Changed EEPROM:");
    PrintAll();
}

void C_EepromManager::PrintAll(){
    uint8_t brightnessValue = GetBrightness();
    RgbColor colorValue = GetForegroundColor(); 
    Serial.printf("Brightness: %d (size: %u) (address: %u)\n", brightnessValue, sizeof(brightnessValue), EEPROM_ADDRESS_BRIGTHNESS);
    Serial.printf("Foreground Color Red: %d (size: %u) (address: %u)\n", colorValue.R, sizeof(colorValue.R), EEPROM_ADDRESS_COLOR_R);
    Serial.printf("Foreground Color Green: %d (size: %u) (address: %u)\n", colorValue.G, sizeof(colorValue.G), EEPROM_ADDRESS_COLOR_G);
    Serial.printf("Foreground Color Blue: %d (size: %u) (address: %u)\n", colorValue.B, sizeof(colorValue.B), EEPROM_ADDRESS_COLOR_B);

}