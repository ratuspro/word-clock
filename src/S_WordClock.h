#include <Screen.h>
#include <bitset>
#include <config.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <memory>

class S_WordClock : public Screen {
   public:
    S_WordClock();
    void Update();

   private:
    bool _timeSet;
    std::bitset<NUM_LEDS> ConvertTimeToLeds(int hours, int minutes);
    std::unique_ptr<NTPClient> _client;
    std::unique_ptr<WiFiUDP> _udp;

};