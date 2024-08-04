#ifndef ORDER_H
#define ORDER_H

#include "../include/main.h"
#include "../include/date.h"

namespace orderInfo{
    class order{
        public:
            //Constructor
            order(std::string firstName, std::string lastName, int customerID, std::string dropOff, std::string pickUp, std::array<std::tuple<int, double>, 8> articles);
            order(int orderID, std::string firstName, std::string lastName, int customerID, std::string dropOff, std::string pickUp, std::array<std::tuple<int, double>, 8> articles, double cost);
            order(int orderID, std::string firstName, std::string lastName, int customerID, std::string dropOff, std::string pickUp, std::array<std::tuple<int, double>, 8> articles);

            //Get functions, set to const to insure that data isn't being changed
            int getCustomerID() const;
            int getOrderID() const;
            std::string getName() const;
            std::string getFirstName() const;
            std::string getLastName() const;
            std::string getDropOffDate() const;
            std::string getPickUpDate() const;
            std::array<std::tuple<int, double>, 8> getDetails() const;
            double getCost() const;
            int getRack() const;
            bool getPickUp() const;


            //Set functions 
            int setCustomerID(int id);
            int setFirstName(std::string firstName);
            int setLastName(std::string lastName); 
            int setDropOffDate(std::string date); 
            int setPickUpDate(std::string date); 
            int setDetails(std::array<std::tuple<int, double>, 8> articles);
            int setCost(double cost);
            int setRack(int rack);
            int setPickUp(bool pickUp);
            
            //Helper functions
            double calculateCost(int* articles);
            int generateOrderID(); 

            //order& operator=(const order& other);

            //Serialize  
            void serialize(std::ofstream& ofs) const;
            static order deserialize(std::ifstream& ifs);
            date::Date* dropOff;
            date::Date* pickUp;

        private: 
            int customerID;
            int orderID;

            std::string firstName;
            std::string lastName;

            //Dates and time will be Chars to keep it simple 
            //mm/dd/yy
            //date::Date 
            std::string dropOffDate;
            
            //hh:mm<pm/am>
            std::string pickUpDate;
            
            
            //[0]: Shirts, [1]: Pants, [2]:Sweaters, [3]:Coats, [4]:Blouses, [5]:2pc Suit, [6]:Jacket, [7]:Vest 
            std::array<std::tuple<int, double>, 8> articles;
            
            double cost;
            int rackNumber;
            bool pickedUp;


    };
}

#endif