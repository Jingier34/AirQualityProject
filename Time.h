#ifndef FINALPROJECT_TIME_H
#define FINALPROJECT_TIME_H

#include <iostream>

class Time {
public:
    Time();
    Time(int hh, int mm, int ss);

    int GetHour() const;
    int GetMin() const;
    int GetSec() const;

    void SetHour(int hh);
    void SetMin(int mm);
    void SetSec(int ss);
    void SetTime(int hh, int mm, int ss);

    void printTime() const;

    bool operator==(const Time &otherTime) const;

    friend std::ostream &operator<<(std::ostream &os, const Time &T);
    friend std::istream &operator>>(std::istream &input, Time &T);

private:
    int hour;
    int min;
    int sec;
};

#endif // FINALPROJECT_TIME_H
