#include "main.h"

namespace date{
    class Date{
        public:
            //get functions 
            int getDay() const;
            int getMonth() const;
            int getYear() const;
            std::string getDate() const;

            int getHour() const;
            int getMin() const;
            std::string getTime() const;
            std::string getAm_Pm() const;


            //set functions
            int setDay(int day);
            int setMonth(int Month);
            int setYear(int year);
            int setDate(std::string date);

            int setHour(int hour);
            int setMin(int min);
            int setTime(std::string time);
            int setAm_Pm(std::string am_pm);

            //helper functions



        private:
            int day;
            int month;
            int year; 
            std::string date;

            int hour;
            int min;
            std::string am_pm;
            std::string time;
            
    };
}