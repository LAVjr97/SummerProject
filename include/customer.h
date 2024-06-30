#include <iostream>
#include <cassert>

namespace cust{
	class customer{ 
		public: 
			//Constructors 
			customer(std::string name, std::string phone);
			customer(std::string name);

			//Get functions 
			int getCustomerID() const; 
			std::string getName() const; 
			std::string getPhone() const; 
			std::string getLastVisit() const; 
			int getVisit() const; 
			double getTotal() const; 

			//Set functions
			int setCustomerID(int id);
			int setName(std::string name);
			int setPhone(std::string phone);
			int updateLastVisit(std::string lastVisit);
			int updateVisits(int visits);
			int updateTotal(double total);

		private:
			int customerID; 
			std::string name; 
			std::string phone; 
			std::string lastVisit; 
			int visits; 
			double total;  
	};
}



