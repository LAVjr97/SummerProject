#include "../include/order.h"

using namespace orderInfo;

//Constructor
order::order(std::string name, int customerID, std::string dropOff, std::string pickUp, std::array<std::tuple<int, double>, 8> articles, double cost){
    this->orderID = order::generateOrderID(); 
    this->dropOffDate = dropOff; 
    this->pickUpDate = pickUp; 
    this->articles = articles; 
    this->cost = cost; 
} 

order::order(int orderID, std::string name, int customerID, std::string dropOff, std::string pickUp, std::array<std::tuple<int, double>, 8> articles, double cost){
    this->orderID = orderID; 
    this->dropOffDate = dropOff; 
    this->pickUpDate = pickUp; 
    this->articles = articles; 
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
    //size_t = unsigned integer type of the result of sizeof
    size_t nameSize = name.size();

    ofs.write(reinterpret_cast<const char*>(&this->orderID), sizeof(this->orderID)); 

    ofs.write(reinterpret_cast<const char*>(&this->name), sizeof(nameSize));
    ofs.write(name.c_str(), nameSize);

    





}
orderInfo::order order::deserialize(std::ifstream& ifs){
    int orderId;
    ifs.read(reinterpret_cast<char*>(&orderId), sizeof(orderId));

    int customerId;
    ifs.read(reinterpret_cast<char*>(&customerId), sizeof(customerId));

    size_t customerNameSize;
    ifs.read(reinterpret_cast<char*>(&customerNameSize), sizeof(customerNameSize));
    std::string customerName(customerNameSize, ' ');
    ifs.read(&customerName[0], customerNameSize);

    size_t dropOffDateSize;
    ifs.read(reinterpret_cast<char*>(&dropOffDateSize), sizeof(dropOffDateSize));
    std::string dropOffDate(dropOffDateSize, ' ');
    ifs.read(&dropOffDate[0], dropOffDateSize);

    size_t pickUpDateSize;
    ifs.read(reinterpret_cast<char*>(&pickUpDateSize), sizeof(pickUpDateSize));
    std::string pickUpDate(pickUpDateSize, ' ');
    ifs.read(&pickUpDate[0], pickUpDateSize);

    //adress to tup, tup iterates over articles, so any change done to tup is a change to articles because of the "& "
    
    std::array<std::tuple<int, double>, 8> articles; 
    for(auto& tup: articles){
        int i; 
        double d;

        ifs.read(reinterpret_cast<char*>(&i), sizeof(i));
        ifs.read(reinterpret_cast<char*>(&d), sizeof(d));
        
        tup = std::make_tuple(i, d);
    }

    double cost;
    ifs.read(reinterpret_cast<char*>(&cost), sizeof(cost));

    //std::string name, int customerID, std::string dropOff, std::string pickUp, std::array<std::tuple<int, double>, 8> description, double cost
   
    return orderInfo::order(orderId, customerName, customerId, dropOffDate, pickUpDate, articles, cost);

}