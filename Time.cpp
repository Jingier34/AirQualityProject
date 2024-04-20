#include "Time.h"

Time::Time() : hour(0), min(0), sec(0) {}

Time::Time(int hh, int mm, int ss) : hour(hh), min(mm), sec(ss) {}

int Time::GetHour() const {
    return hour;
}

int Time::GetMin() const {
    return min;
}

int Time::GetSec() const {
    return sec;
}

void Time::SetHour(int hh) {
    hour = hh;
}

void Time::SetMin(int mm) {
    min = mm;
}

void Time::SetSec(int ss) {
    sec = ss;
}

void Time::SetTime(int hh, int mm, int ss) {
    hour = hh;
    min = mm;
    sec = ss;
}

void Time::printTime() const {
    std::cout << hour << ":" << min << ":" << sec;
}

bool Time::operator==(const Time &otherTime) const {
    return (hour == otherTime.hour && min == otherTime.min && sec == otherTime.sec);
}

std::istream &operator>>(std::istream &input, Time &T) {
    char colon1, colon2;
    int hh, mm, ss;
    input >> hh >> colon1 >> mm >> colon2 >> ss;
    if (!input || colon1 != ':' || colon2 != ':') {
        throw std::invalid_argument("Invalid time format");
    }
    T.SetTime(hh, mm, ss);
    return input;
}

std::ostream &operator<<(std::ostream &os, const Time &T) {
    os << (T.hour < 10 ? "0" : "") << T.hour << ":"
       << (T.min < 10 ? "0" : "") << T.min << ":"
       << (T.sec < 10 ? "0" : "") << T.sec;
    return os;
}
