#include <iostream>
#include <iomanip>
#include <string>
#include "stdint.h"
#include "DateTime.h"

void DateTime::setDay(int day)
{
    this->day = day;
}

void DateTime::setMonth(int month)
{
    this->month = month;
}

void DateTime::setYear(int year)
{
    this->year = year;
}

int DateTime::getDay()
{
    return this->day;
}

int DateTime::getMonth()
{
    return this->month;
}

int DateTime::getYear()
{
    return this->year;
}

DateTime::DateTime(int day,int month,int year)
{
    this->day=day;
    this->month=month;
    this->year=year;
}
DateTime::DateTime(){};

void DateTime::nextDay(int day)
{
    this->day += day;
    while(this->day>30||this->month>12) {
        if (this->day > 30) {
            this->month += 1;
            this->day = 1;
        }
        if (this->month > 12) {
            this->year += 1;
            this->month = 1;
        }
    }
}

std::string DateTime::getTime()
{
    std::string str,day=std::to_string(getDay()),month=std::to_string(getMonth()),year=std::to_string(getYear());
    str=day+"."+month+"."+year;
    return str;
}
