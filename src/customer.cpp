#include "include/customer.h";

using namespace cust;


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
	
	return 0;
}
int customer::setName(std::string name) {

	return 0;
}

int setPhone(std::string phone);
int updateLastVisit(std::string lastVisit);
int updateVisits(int visits);
int updateTotal(double total);
