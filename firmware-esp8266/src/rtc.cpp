#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;

dateTime now;

void setup() {
    Wire.begin();
    rtc.begin();
}

void setTime(int year, int month, int day, int hour, int minute, int second) {
    rtc.adjust(DateTime(year, month, day, hour, minute, second));
}

DateTime getTime() {
    return rtc.now();
}

float getTemperature() {
    return rtc.getTemperature();
}

void loop() {
    // Example usage
    dateTime now = getTime();
    Serial.println(String(now.year()) + "-" + String(now.month()) + "-" + String(now.day()) + " " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second()));
    Serial.println("Temperature: " + String(getTemperature()) + " °C");
    delay(1000);
}