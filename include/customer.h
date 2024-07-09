#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

namespace cust{
	class customer{ 
		public: 
			//Constructors & Destructor
			customer(int customerID, std::string name, std::string phone, int visits, double total);
			customer(std::string name, std::string phone);
			customer(std::string name);
			~customer();

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

			//Helper functions
			int generateCustomerID(); 

			//serialize functions
			void serialize(std::ofstream &ofs) const;
			static customer deserialize(std::ifstream& ifs);
			

		private:
			int customerID; 
			std::string name; 
			std::string phone; 
			std::string lastVisit; 
			int visits; 
			double total;  
	};
}



