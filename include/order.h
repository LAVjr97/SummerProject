#include <iostream>
#include <cassert>
#include <string>

namespace OrderInfo{
    class order{
        public:
            //Constructor
            order(std::string dropOff, std::string pickUp, int* description, double cost);
        
            //Get functions, set to const to insure that data isn't being changed
            int getCustomerID() const;
            int getOrderID() const;
            std::string getDropOffDate() const;
            std::string getPickUpDate() const;
            int* getDetails() const;
            double getCost() const;

            //Set functions
            int setCustomerID(int id);
            int generateOrderID();
            int setDropOffDate(std::string date);
            int setPickUpDate(std::string date); 
            int setDetails(int* articles);
            int setCost(double cost);
            
            //Helper functions
            double calculateCost(int* articles);

        private: 
            int customerID;
            int orderID;

            //Dates and time will be Chars to keep it simple, [0] is the date, [1] is the time formatted, hh:mm, initialize as std::string* date = new std::string[2];
            std::string dropOffDate;
            std::string pickUpDate;
            
            //[0]: Shirts, [1]: Pants, [2]:Sweaters, [3]:Coats, [4]:Blouses, [5]:2pc Suit, [6]:Jacket, [7]:Vest 
            int* articles;
            
            double cost;
    };
}