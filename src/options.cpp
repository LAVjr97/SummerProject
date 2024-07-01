#include "../include/menuHeader.h"
#include "../include/order.h"

 
using namespace menu;

int options::handleDropOff() {
    system("cls");
    cout << "\nhandleDropOff";

    std::string dropOff = options::getDate(), date, time, pickUp, name;
    std::array<std::tuple<int, double>, 8> articles;
    double cost = 0.99;

    cout << "\nCustomer Name:\n";

    cin >> pickUp;

    cout << "\n ";
    //cin >> 
    //cout << "\n ";
    cout << "\nPick Up Date? <mm/dd/yy>";
    cin >> date;

    cout << "\nTime? <hh:mm pm>";
    cin >> time;
    pickUp = date + " " + time;



    //OrderInfo::order customerOrder();
    OrderInfo::order orderA(name, dropOff, pickUp, articles, cost);

    //save function before returning to main menu, there will be an auto save feature and a manual save before exiting to main menu. 
    //delete[] dropOff; 
    return 0;
}

int options::handlePickUp() {
    system("cls");
    cout << "\nhandlePickUp";
    return 0;
}

int options::handleLookUp() {
    system("cls");
    cout << "\nhandleLookUp";
    return 0;
}

int options::handleHistory() {
    system("cls");
    cout << "\nhandleDropOff";
    return 0;
}

std::array<std::tuple<int, double>, 8> handleArticles() {
    std::array<std::tuple<int, double>, 8> articles;
    for(int i; i < 8; i++){
        switch (i) {
            case 0:
                cout << "\n Number of pants?"
                articles
            case 1: 

            case 2: 

            case 3:

            case 4: 

            case 5: 

            case 6: 

            case 7:
        }
    }



    return articles;
}

//Returns the current date and time, Foramatted: mm/dd/yy hh:mm <am/pm>
std::string options::getDate() {
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);
    int year = localTime->tm_year - 100; //tm_year returns the year starting from 1900, so 2024 is 124 - 100 = 24
    int month = localTime->tm_mon + 1;
    int day = localTime->tm_mday;
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    static std::string temp;

    //Sets the time to am or pm depending on the time of day. 
    if (hour > 12) {
        hour = hour % 12;
        temp = std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + " " + std::to_string(hour) + ":" + std::to_string(minute) + "pm";
    }
    else 
        temp = std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + " " + std::to_string(hour) + ":" + std::to_string(minute) + "am";
    

    //std::string* date = &temp;
    return temp;
}