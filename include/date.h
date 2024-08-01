#include "main.h"

namespace date{
    class Date{
        public:
            Date(std::string fullDate);

            //get functions 
            int getDay() const;
            int getMonth() const;
            int getYear() const;
            std::string getDate() const;

            int getHour() const;
            int getMin() const;
            std::string getAm_Pm() const;
            std::string getTime() const;
            


            //set functions
            int setDay(int day);
            int setMonth(int Month);
            int setYear(int year);
            int setDate(std::string date);

            int setHour(int hour);
            int setMin(int min);
            int setAm_Pm(std::string am_pm);
            int setTime(std::string time);
            

            //helper functions
            std::string createExistingDate()const;
            std::string createExistingTime()const;

        private:
            int day;
            int month;
            int year; 
            std::string date;

            int hour;
            int min;
            std::string am_pm;
            std::string time;

            std::string date_time;
            
    };
}