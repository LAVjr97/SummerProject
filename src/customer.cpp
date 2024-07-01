#include "include/customer.h"

using namespace cust;

//Constructor
customer::customer(std::string name, std::string phone){
	customer::name = name;
	customer::phone = phone; 
	customer::visits = 0;
	customer::total = total;

}

customer::customer(std::string name){

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

int customer::setCustomerID(int id) {
	customer::customerID = id; 
	return 0;
}
int customer::setName(std::string name) {
	customer::name = name;
	return 0;
}

int customer::setPhone(std::string phone){
	customer::phone = phone;
	return 0;
}
int customer::updateLastVisit(std::string lastVisit){
	customer::lastVisit = lastVisit;
	return 0;
}
int customer::updateVisits(int visits){
	customer::visits = visits;
	return 0;
}
int customer::updateTotal(double total){
	customer::total = total;
	return 0;
}
