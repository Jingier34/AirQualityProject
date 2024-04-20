//
// Created by 白白 on 2024/4/19.
//

#ifndef FINALPROJECT_AIRQUALITY_H
#define FINALPROJECT_AIRQUALITY_H


#include "Date.cpp"
#include "Time.cpp"

class AirQuality {
public:
    AirQuality();
    AirQuality(Date D, Time T, double t, double rh, double ah);

    Date GetDate() const;
    Time GetTime() const;
    double GetTemperature() const;
    double GetRelativeHumidity() const;
    double GetAbsoluteHumidity() const;

    void SetDate(const Date& D);
    void SetTime(Time T);
    void SetTemperature(double t);
    void SetRelativeHumidity(double rh);
    void SetAbsoluteHumidity(double ah);

private:
    Date date;
    Time time;
    double temperature;
    double relativeHumidity;
    double absoluteHumidity;
};

#endif //FINALPROJECT_AIRQUALITY_H
