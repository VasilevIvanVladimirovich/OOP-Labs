#ifndef LAB_OOP_DATETIME_H
#define LAB_OOP_DATETIME_H
#pragma once
#include <string>
class DateTime
{
public:

    void setDay(int day);

    void setMonth(int Month);

    void setYear(int year);

    int getDay();

    int getMonth();

    int getYear();

    void nextDay(int day);

    std::string getTime();

    DateTime(int day,int month,int year);

    DateTime();

private:
    int day;
    int month;
    int year;
};



#endif //LAB_OOP_DATETIME_H
