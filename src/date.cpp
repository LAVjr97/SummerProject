#include "../include/date.h"

using namespace date;

int Date::getDay() const{
    return this->day;
}

int Date::getMonth() const{
    return this->month;
}

int Date::getYear() const{
    return this->year;
}

std::string Date::getDate() const{
    return this->date;
}

int Date::getHour() const{
    return this->hour;
}

int Date::getMin() const{
    return this->min;
}

std::string 