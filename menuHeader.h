//Notes: To clear screen on Unix based os', use "clear", windows, "cls"

#include <string>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include "order.h"
#include <ctime> 


using namespace std;

namespace menu{
    class options{
        public: 
            //Static functions, functions to be used through out run time. 
            static int handleDropOff();
            static int handlePickUp();
            static int handleLookUp();
            static int handleHistory();
            
            static std::string* getDate();

        private: 

    };

    int options::handleDropOff(){
        std::string* dropOff;
        std::string* pickUp;
        int* articles = new int[8];
        double cost = .99;


        system("clear"); 
        cout << "\nhandleDropOff";

        dropOff = options::getDate();

        cout << "\n ";
        cin >> pickUp[0];

        cout << "\n ";
        cin >> pickUp[1];

        cout << "\n ";
        cin >> 
        cout << "\n ";

    
        OrderInfo::order customerOrder();


        //save function before returning to main menu, there will be an auto save feature and a manual save before exiting to main menu. 
        delete[] dropOff; 
        delete[] articles;
        return 0;
    }

    int options::handlePickUp(){
        system("clear");
        cout << "\nhandlePickUp";
        return 0;
    }

    int options::handleLookUp(){
        system("clear");
        cout << "\nhandleLookUp";
        return 0;
    }

    int options::handleHistory(){
        system("clear");
        cout << "\nhandleDropOff";
        return 0;
    }

    //Returns the current date and time, Foramatted: mm/dd/yy hh:mm <am/pm>
    std::string* options::getDate(){
        std::time_t currentTime = std::time(nullptr);
        std::tm* localTime = std::localtime(&currentTime);
        int year = localTime->tm_year - 100;
        int month = localTime->tm_mon + 1;
        int day = localTime->tm_mday;
        int hour = localTime->tm_hour;
        int minute = localTime->tm_min;
        std::string temp;

        //Sets the time to am or pm depending on the time of day. 
        if(hour > 12){
            hour = hour % 12; 
            temp = std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + " " + std::to_string(hour) + ":" + std::to_string(minute) + "pm";
        }
        else{
            temp = std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + " " + std::to_string(hour) + ":" + std::to_string(minute) + "am";
        }

        std::string* date = &temp;
        return date;
    }
}



