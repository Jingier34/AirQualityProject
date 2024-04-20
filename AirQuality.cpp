//
// Created by 白白 on 2024/4/19.
//

#include "AirQuality.h"

AirQuality::AirQuality() {
    date = Date();
    time = Time();
    temperature = 0;
    relativeHumidity = 0;
    absoluteHumidity = 0;
}
AirQuality::AirQuality(Date D, Time T, double t, double rh, double ah) {
    date = D;
    time = T;
    temperature = t;
    relativeHumidity = rh;
    absoluteHumidity = ah;
}

Date AirQuality::GetDate() const { return date; }
Time AirQuality::GetTime() const { return time; }
double AirQuality::GetTemperature() const { return temperature; }
double AirQuality::GetRelativeHumidity() const { return relativeHumidity; }
double AirQuality::GetAbsoluteHumidity() const { return absoluteHumidity; }

//void AirQuality::SetDate(basic_string<char, char_traits<char>, allocator<char>> D) { date = D; }
void AirQuality::SetDate(const Date& D) {
    date = D;
}
void AirQuality::SetTime(Time T) { time = T; }
void AirQuality::SetTemperature(double t) { temperature = t; }
void AirQuality::SetRelativeHumidity(double rh) { relativeHumidity = rh; }
void AirQuality::SetAbsoluteHumidity(double ah) { absoluteHumidity = ah; }