#include <NTPClient.h>
#include <S_WordClock.h>
#include <WiFiUdp.h>
#include <Core.h>

S_WordClock::S_WordClock(Core* owner) : Screen(owner){
    
}

void S_WordClock::Update() {
    switch (_currentState) {
        case State::RUNNING:

            break;
        case State::ENTERING:
            GetTimeFromNTC();
            break;
        case State::EXITING:

            break;
        default:
            break;
    }
}

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

void S_WordClock::GetTimeFromNTC() {
    timeClient.begin();
    timeClient.setTimeOffset(3600);
    while (!timeClient.update()) {
        timeClient.forceUpdate();
    }
    Serial.println(timeClient.getFormattedTime());
}