#include "../include/date.h"

using namespace date;

Date::Date(std::string fullDate){

}


//Get functions
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

std::string Date::getAm_Pm() const{
    return this->am_pm;
}

std::string Date::getTime() const{
    return this->time;
}

std::string Date::getDate_Time() const{
    return this->date_time;
}

//Set functions
int Date::setDay(int date){
    this->date = date;
    return 0;
}

int Date::setMonth(int month){
    this->month = month;
    return 0;
}

int Date::setYear(int year){
    this->year = year;
    return 0;
}

int Date::setDate(std::string date){
    this->date = date;
    return 0;
}

int Date::setHour(int hour){
    this->hour = hour;
    return 0;
}

int Date::setMin(int min){
    this->min = min;
    return 0;
}

int Date::setAm_Pm(std::string am_pm){
    this->am_pm = am_pm;
    return 0;
}

int Date::setTime(std::string time){
    this->time = time;
    return 0;
}

int Date::setDate_Time(std::string date_time){
    this->date_time = date_time;
    return 0;
}
