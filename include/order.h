#include <iostream>
#include <cassert>
#include <string>
#include <tuple>
#include <array>
#include <fstream>
#include <cstring>


namespace orderInfo{
    class order{
        public:
            //Constructor
            order(std::string name, int customerID, std::string dropOff, std::string pickUp, std::array<std::tuple<int, double>, 8> description, double cost);
        
            //Get functions, set to const to insure that data isn't being changed
            int getCustomerID() const;
            int getOrderID() const;
            std::string order::getName() const;
            std::string getDropOffDate() const;
            std::string getPickUpDate() const;
            std::array<std::tuple<int, double>, 8> getDetails() const;
            double getCost() const;

            //Set functions 
            int setCustomerID(int id);
            int setName(std::string name); 
            int setDropOffDate(std::string date); 
            int setPickUpDate(std::string date); 
            int setDetails(std::array<std::tuple<int, double>, 8> articles);
            int setCost(double cost);
            
            //Helper functions
            double calculateCost(int* articles);
            int generateOrderID(); 

            //Serialize 
            void serialize(std::ofstream& out) const;
            void deserialize(std::ifstream& in);
            
        private: 
            int customerID;
            int orderID;

            std::string name;

            //Dates and time will be Chars to keep it simple 
            std::string dropOffDate;
            std::string pickUpDate;
            
            //[0]: Shirts, [1]: Pants, [2]:Sweaters, [3]:Coats, [4]:Blouses, [5]:2pc Suit, [6]:Jacket, [7]:Vest 
            std::array<std::tuple<int, double>, 8> articles;
            
            double cost;
    };
}