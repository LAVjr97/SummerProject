#include "../include/customer.h"

using namespace cust;

//Constructor
customer::customer(std::string name, std::string phone){
	this->name = name;
	this->phone = phone; 
	this->visits = 0;
	this->total = 0;

}

customer::customer(std::string name){
	this->name = name;
	this->customerID = customer::generateCustomerID();
}

//Get functions 
int customer::getCustomerID() const{
	return customerID;
}

std::string customer::getName() const{
	return name; 
}

std::string customer::getPhone() const{
	return phone;
}

std::string customer::getLastVisit() const{
	return lastVisit;
}

int customer::getVisit() const{
	return visits;
}
double customer::getTotal() const{
	return total;
}

//Set functions
int customer::setCustomerID(int id) {
	this->customerID = id; 
	return 0;
}
int customer::setName(std::string name) {
	this->name = name;
	return 0;
}

int customer::setPhone(std::string phone){
	this->phone = phone;
	return 0;
}

int customer::updateLastVisit(std::string lastVisit){
	this->lastVisit = lastVisit;
	return 0;
}

int customer::updateVisits(int visits){
	this->visits = visits;
	return 0;
}

int customer::updateTotal(double total){
	this->total = total;
	return 0;
}

//Helper functions
int customer::generateCustomerID(){
	int id = 0; 
	
	//pull up latest id used, "++"" it, update and save the latest ID


	return id;
} 


//Serialize functions
void customer::serialize(std::ofstream &ofs) const{

}

customer customer::deserialize(std::ifstream& ifs){

}