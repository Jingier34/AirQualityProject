// Date.cpp
#include "Date.h"
#include <iostream>

Date::Date() : month(1), day(1), year(2000) {}

Date::Date(int MM, int dd, int yyyy) : month(MM), day(dd), year(yyyy) {}

int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getYear() const { return year; }

void Date::SetMonth(int MM) { month = MM; }
void Date::SetDay(int dd) { day = dd; }
void Date::SetYear(int yyyy) { year = yyyy; }
void Date::SetDate(int MM, int dd, int yyyy) {
    month = MM;
    day = dd;
    year = yyyy;
}

void Date::printDate() const { std::cout << month << "/" << day << "/" << year; }

bool Date::operator==(const Date &otherDate) const {
    return (month == otherDate.month && day == otherDate.day && year == otherDate.year);
}

std::istream &operator>>(std::istream &input, Date &D) {
    char slash1, slash2;
    int MM, dd, yyyy;
    input >> MM >> slash1 >> dd >> slash2 >> yyyy;
    if (!input || slash1 != '/' || slash2 != '/') {
        throw std::invalid_argument("Invalid date format");
    }
    D.SetMonth(MM);
    D.SetDay(dd);
    D.SetYear(yyyy);
    return input;
}

std::ostream &operator<<(std::ostream &os, const Date &D) {
    os << D.getMonth() << "/" << D.getDay() << "/" << D.getYear();
    return os;
}