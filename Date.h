//
// Created by 白白 on 2024/4/19.
//

// Date.h
#ifndef FINALPROJECT_DATE_H
#define FINALPROJECT_DATE_H

#include <iostream>

class Date {
public:
    Date();
    Date(int MM, int dd, int yyyy);

    int getMonth() const;
    int getDay() const;
    int getYear() const;

    void SetMonth(int MM);
    void SetDay(int dd);
    void SetYear(int yyyy);
    void SetDate(int MM, int dd, int yyyy);

    void printDate() const;

    bool operator==(const Date &otherDate) const;

    friend std::istream &operator>>(std::istream &input, Date &D);
    friend std::ostream &operator<<(std::ostream &os, const Date &D);

private:
    int month;
    int day;
    int year;
};

#endif // FINALPROJECT_DATE_H