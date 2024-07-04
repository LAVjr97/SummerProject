#include "../include/order.h"

using namespace orderInfo;

//Constructor
order::order(std::string name, int customerID, std::string dropOff, std::string pickUp, std::array<std::tuple<int, double>, 8> description, double cost){
    this->orderID = order::generateOrderID();
    this->dropOffDate = dropOff;
    this->pickUpDate = pickUp;
    this->articles = description;
    this->cost = cost; 
}

/*Get Functions*/
int order::getCustomerID() const{
    return customerID;
}

int order::getOrderID() const{
    return orderID;
}

std::string order::getName() const{
    return name;
}

std::string order::getDropOffDate() const{
    return dropOffDate; 
}

std::string order::getPickUpDate() const{
    return pickUpDate;
}

std::array<std::tuple<int, double>, 8> order::getDetails() const{
    return articles;
}

double order::getCost() const{
    return cost;
}

/*Set Functions*/
int order::setCustomerID(int id){
    this->customerID = id;
    return 0;
}

int order::generateOrderID(){
    this->orderID = 10;
    return 0;
}

int order::setName(std::string name){
    this->name = name;
    return 0;
}

int order::setDropOffDate(std::string date){
    //date = new std::string[2];
    this->dropOffDate = date;
    return 0;
}

int order::setPickUpDate(std::string date){
    this->pickUpDate = date;
    return 0;
}

int order::setDetails(std::array<std::tuple<int, double>, 8> articles){
    this->articles = articles;
    return 0;
}

int order::setCost(double cost){
    this->cost = cost;
    return 0; 
}

double order::calculateCost(int* articles) {
    return 0;
}

int order::generateOrderID(){ 
    int id; 
    //pull up latest id used, "++"" it, update and save the latest ID

    return id;
}

//Serialize functions
void order::serialize(std::ofstream& ofs) const{
    ofs.write(reinterpret_cast<const char*>(&order::orderID), sizeof(order::orderID));

}
void deserialize(std::ifstream& in){

}