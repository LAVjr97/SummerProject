#include "../include/order.h"

using namespace OrderInfo;

//Constructor
order::order(std::string name, std::string dropOff, std::string pickUp, std::array<std::tuple<int, double>, 8> description, double cost){
    //generateID();
    order::dropOffDate = dropOff;
    order::pickUpDate = pickUp;
    order::articles = description;
    order::cost = cost; 
}

//Get Functions
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

//Set Functions
int order::setCustomerID(int id){
    order::customerID = id;
    return 0;
}

int order::generateOrderID(){
    order::orderID = 10;
    return 0;
}

int order::setName(std::string name){
    order::name = name;
    return 0;
}

int order::setDropOffDate(std::string date){
    //date = new std::string[2];
    order::dropOffDate = date;
    return 0;
}

int order::setPickUpDate(std::string date){
    order::pickUpDate = date;
    return 0;
}

int order::setDetails(std::array<std::tuple<int, double>, 8> articles){
    order::articles = articles;
    return 0;
}

int order::setCost(double cost){
    order::cost = cost;
    return 0; 
}

double order::calculateCost(int* articles) {

    return 0;
}