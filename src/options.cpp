#include "../include/menuHeader.h"
#include "../include/order.h"
#include "../include/customer.h"

//To clear the screen, windows uses "cls", mac/linux uses "clear" 
#define screen "cls"

using namespace menu;

int options::handleDropOff() {
    //Clear the Screen
    system(screen);
    cout << "\nhandleDropOff";

    //Initialize variables
    std::string dropOff = options::getDate(), date, time, pickUp, firstName, lastName, firstTime, number;
    std::array<std::tuple<int, double>, 8> articles;
    double cost = 0.99;
    int customerID = 0;

    //Customer Info
    cout << "\nIs this a first-time cusomter? <Yes/No>\n";
    cin >> firstTime;
    cout << "\nCustomer First Name:\n";
    cin >> firstName;
    cout << "\nCustomer Last Name:\n";
    cin >> lastName;

    if(firstTime == "Yes" || "yes" || "y" || "Y"){
        cout << "\nCustomer Phone Number?\n";
        cin >> number;
        cust::customer* customerA = new cust::customer(firstName, lastName, number);
   }else
        /**have the stored customer info pulled up (name and customerID)**/

    //Order Info
    cout << "\nPick Up Day? <mm/dd/yy>\n";
    cin >> date;

    cout << "\nPick Up Time? <hh:mm <am/pm>>\n";
    cin >> time;
    pickUp = date + " " + time;
    articles = handleArticles();
    orderInfo::order* orderA = new orderInfo::order(firstName, lastName, customerID, dropOff, pickUp, articles, cost);


    //Have the customer 
    //save function before returning to main menu, there will be an auto save feature and a manual save before exiting to main menu. 
    return 0;
}

int options::handlePickUp() {
    system(screen);
    cout << "\nhandlePickUp";
    return 0;
}

int options::handleLookUp() {
    system(screen);
    cout << "\nhandleLookUp";
    return 0;
}

int options::handleHistory() {
    system(screen);
    cout << "\nhandleDropOff";
    return 0;
}

//Creates a menu from where the user selects a piece of clothing and then inputs the number of pieces of that particular clothing 
std::array<std::tuple<int, double>, 8> handleArticles() { 
    //[0]: Shirts, [1]: Pants, [2]:Sweaters, [3]:Coats, [4]:Blouses, [5]:2pc Suit, [6]:Jacket, [7]:Vest 
    std::array<std::tuple<int, double>, 8> articles; 
    int article, n;

    while(true){
        cout << "\nEnter article number (or '0' to go save and return):\n1) Shirts\n2) Pants\n3) Sweaters\n4) Coats\n5) Blouses\n6) 2pc Suit\n7) Jackets\n7) Vest\n";
        cin >> article;

        switch(article){
            case 1:
                cout << "\nNumber of Shirt(s)?\n";
                cin >> n; 
                articles[0] = std::make_tuple(n, 4.99);

            case 2: 
                cout << "\nNumber of Pant(s)?\n";
                cin >> n; 
                articles[1] = std::make_tuple(n, 4.99);

            case 3: 
                cout << "\nNumber of Sweater(s)?\n";
                cin >> n; 
                articles[2] = std::make_tuple(n, 5.99);

            case 4: 
                cout << "\nNumber of Coat(s)?\n";
                cin >> n; 
                articles[3] = std::make_tuple(n, 6.99);

            case 5: 
                cout << "\nNumber of Blouse(s)?\n";
                cin >> n; 
                articles[3] = std::make_tuple(n, 4.50);

            case 6: 
                cout << "\nNumber of 2pc Suit(s)?\n";
                cin >> n; 
                articles[4] = std::make_tuple(n, 12.99);

            case 7: 
                cout << "\nNumber of Jacket(s)?\n";
                cin >> n; 
                articles[4] = std::make_tuple(n, 6.99);

            case 8: 
                cout << "\nNumber of Vest(s)?\n";
                cin >> n; 
                articles[4] = std::make_tuple(n, 3.99);

            case 0: 
                return articles; 
            default: 
                continue;
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