#include <iostream>
#include <cassert>

namespace cust{
	class customer {
		public: 
			//Constructors
			customer(); 

			//Get functions
			int getCustomerID() const; 
			std::string getName() const; 
			std::string getPhone() const; 
			std::string getLastVisit() const; 
			int getVisit() const; 
			double getTotal() const; 

			//Set functions
			int generateCustomerID();
			int setName();
			int setPhone();
			int updateLastVisit();
			int updateVisits();
			int updateTotal();


		private:
			int customerID;
			std::string name;
			std::string phone;
			std::string lastVisit;
			int visits;
			double total;

	};
}


