# GAIPS' Word Clock

This repository contains all the code for [GAIPS](https://gaips.inesc-id.pt/)' word clock. This project was fully designed, built, and developed by GAIPS's researchers. The authors of this project are:

- Diogo Rato @ratuspro
- João Higino @higin0

## Description

The clock shows the current time with a 5 minute precision. Most of the elements of the clock are adjustable (time, color, and brightness). 

## Usage

The clock's buttons are placed in the right side of the clock's face. The buttons are:

- UP (next to letter upper 'O')
- DOWN (next to letter 'R')
- ENTER (next to letter 'E')
- MENU (next to letter lower 'O')

There are two ways to define the clock's time:

- When it starts, the clock will try to connect to an WiFi with the defined credentials (in code). If a connection is sucessfully established, the clock requests from a NTP Server the current time.
- When the clock is running, pressing the MENU button changes the clock to the Menu Scren. The first submenu is the the Clock Configuration screen.

### Menu > Clock Configuration
This menu starts with the hour selection and is followed by the minute selection. The words being selected are blinking. Using the UP and DOWN buttons it is possible to iterate through all the minutes and hours. Pressing ENTER Button confirms the selection.

### Menu > Color Configuration
In this menu, it is possible to change the color used to display the current time. There is a set of 20 predefined colors to choose from. Using the UP and DOWN buttons it is possible to select the colors from this set. The selected color is displayed in the large rectangle on top. Pressing ENTER button confirms the color selection. Pressing MENU button discards any changes.

### Menu > Brightness Configuration
In this menu, it is possible to adjust the led brightness. Using the UP and DOWN buttons it is possible to select the brightness level. The circle number of bars represents the intensity. Pressing ENTER button confirms the brightness selection. Pressing MENU button discards any changes.

## Development
It is recommended to use [PlatformIO](https://platformio.org/platformio-ide) IDE in [Visual Studio Code](https://code.visualstudio.com/)

## Components

- ESP32doit Devkit v1
- Power Supply 5v 8A
- DC Power Jack
- 110 Led Strip WS2812B
- 4 Capacitive Touch Sensor

### Libraries
- [NeoPixelBus](https://github.com/Makuna/NeoPixelBus/) - used to control the led array 
- [NTPClient](https://github.com/arduino-libraries/NTPClient?utm_source=platformio&utm_medium=piohome) - used to retrieve the current time from NTP servers
- [Bounce2](https://github.com/thomasfredericks/Bounce2?utm_source=platformio&utm_medium=piohome) - buttons debouncing
