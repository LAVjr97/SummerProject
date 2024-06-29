#include "../include/order.h"

using namespace OrderInfo;

//Constructor
order::order(std::string* dropOff, std::string* pickUp, int* description, double cost){
    //generateID();
    order::dropOffDate = dropOff;
    order::pickUpDate = pickUp;
    order::articles = description;
    order::cost = cost; 
}

//Get Functions
int order::getid() const{
    return id;
}

std::string* order::getDropOffDate() const{
    return dropOffDate; 
}

std::string* order::getPickUpDate() const{
    return pickUpDate;
}

int* order::getDetails() const{
    return articles;
}

double order::getCost() const{
    return cost;
}

//Set Functions
int order::generateID(){
    order::id = 10;
    return 0;
}

int order::setDropOffDate(std::string* date){
    //date = new std::string[2];
    order::dropOffDate = date;
    return 0;
}

int order::setPickUpDate(std::string *date){
    order::pickUpDate = date;
    return 0;
}

int order::setDetails(int* articles){
    order::articles = articles;
    return 0;
}

int order::setCost(double cost){
    order::cost = cost;
    return 0; 
}

