#include "../include/customer.h"

using namespace cust;

//Constructor
customer::customer(int customerID, std::string name, std::string phone, int visits, double total){
	this->name = name;
	this->phone = phone;
	this->visits = visits;
	this->total = total;
}


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
	//size_t = unsigned integer type of the result of sizeof
    size_t nameSize = name.size();
	size_t phoneSize = phone.size();

    ofs.write(reinterpret_cast<const char*>(&this->customerID), sizeof(this->customerID)); 

    ofs.write(reinterpret_cast<const char*>(&this->name), sizeof(nameSize));
    ofs.write(name.c_str(), nameSize);

	ofs.write(reinterpret_cast<const char*>(&this->phone), sizeof(phoneSize));
	ofs.write(phone.c_str(), nameSize);

	ofs.write(reinterpret_cast<const char*>(&this->visits), sizeof(visits));
	ofs.write(reinterpret_cast<const char*>(&this->total), sizeof(total));

	return;
}

customer customer::deserialize(std::ifstream& ifs){
	int customerID, visits;
	double total;
	size_t nameSize, phoneSize;

	ifs.read(reinterpret_cast<char*>(&customerID), sizeof(customerID)); 

	ifs.read(reinterpret_cast<char*>(&nameSize), sizeof(nameSize));
	std::string name(nameSize, ' ');
	ifs.read(&name[0], nameSize);

	ifs.read(reinterpret_cast<char*>(&phoneSize), sizeof(phoneSize));
	std::string phone(phoneSize, ' ');
	ifs.read(&phone[0], phoneSize);

	ifs.read(reinterpret_cast<char*>(&visits), sizeof(visits));

	ifs.read(reinterpret_cast<char*>(&total), sizeof(total));

	return customer(customerID, name, phone, visits, total);
}