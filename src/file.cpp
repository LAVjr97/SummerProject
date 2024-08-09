#include "../include/file.h"

using namespace fi;

//Constructors
File::File(std::string customerFile, std::string orderFile, std::string tempFile, std::vector<cust::customer>& customers, std::vector<orderInfo::order>& orders) : customerFile(customerFile), orderFile(orderFile), tempFile(tempFile), customers(customers), orders(orders)
{}

void File::saveCustomers(cust::customer& customer) const{
    std::ofstream ofs(this->customerFile, std::ios::app);
    std::cout << std::endl << "In saveCustomers" << std::endl;
    
    if (!ofs) {
        std::cerr << "Error opening file to write to: " << this->customerFile << std::endl;
        return;
    }
    std::cout << std::endl << "before saving to customers.txt" << std::endl;

    ofs << customer.getCustomerID() << ","
        << customer.getFirstName() << ","
        << customer.getLastName() << ","
        << customer.getPhone() << ","
        << customer.getTotal() << ","
        << customer.getVisit() << std::endl;
    ofs.close();
    return;
}

void File::loadCustomers(){
    int id, visits, total;
    std::string line, firstName, lastName, phone, temp; //using a temp variable because not everything that is being read from the file will be a string.

    std::ifstream ifs(this->customerFile);
    if (!ifs) {
        std::cerr << "Error opening file to write to: " << this->customerFile << std::endl;
        return;
    }
    std::cout << std::endl << "Before while loop that reads file" << std::endl;

    while (std::getline(ifs, line)) {
        std::cout << std::endl << "In while loop that reads file" << std::endl;
        std::stringstream ss(line);

        std::getline(ss, temp, ',');
        id = std::stoi(temp);
        std::cout << std::endl << id << std::endl;
        std::getline(ss, firstName, ',');
        std::getline(ss, lastName, ',');
        std::getline(ss, phone, ',');
        std::getline(ss, temp, ',');
        total = std::stoi(temp);
        std::getline(ss, temp, ',');
        visits = std::stoi(temp);

        customers.emplace_back(id, firstName, lastName, phone, visits, total);
    }

    ifs.close();
}

void File::saveOrders(orderInfo::order &order) const{
    std::ofstream ofs(this->orderFile, std::ios::app);
    std::cout << std::endl << "In saveOrders" << std::endl;

    if (!ofs) {
        std::cerr << "Error opening file to write to: " << this->orderFile << std::endl;
        return;
    }
    
    ofs << order.getCustomerID() << ","
        << order.getOrderID() << ","
        << order.getCost() << ","
        << order.getRack() << ","
        << order.getPickUp() << ","
        << order.dropOff->getDay() << ","
        << order.dropOff->getMonth() << ","
        << order.dropOff->getYear() << ","
        << order.dropOff->getHour() << ","
        << order.dropOff->getMin() << ","
        << order.dropOff->getAm_Pm() << ","
        << order.pickUp->getDay() << ","
        << order.pickUp->getMonth() << ","
        << order.pickUp->getYear() << ","
        << order.pickUp->getHour() << ","
        << order.pickUp->getMin() << ","
        << order.pickUp->getAm_Pm() << ",";
    ofs.close();
    return;
}

void File::loadOrders() {
    //When .emplace_back is being used, the first and last name will be using the address of the variables from that customer's object in case any changes are made to the class, its reflected in the order class.
}

//random functions to go to certain customers to update. 
void File::updateCustomer(const int id) {
    std::string current, line;
    bool found; 

    std::ifstream ifs(this->customerFile);
    std::ofstream tempF(this->tempFile);

    if (!ifs) {
        std::cerr << "Error opening file to write to: " << this->customerFile << std::endl;
        return;
    }
    if (!tempF) {
        std::cerr << "Error opening file to write to: " << this->tempFile << std::endl;
        return;
    }


    while (std::getline(ifs, line)) {
        std::stringstream ss(line); //istringstream
        std::getline(ss, current, ',');

        if (std::stoi(current) == id) {
            found = true;
            tempF << customers[id].getCustomerID() << ","
                << customers[id].getFirstName() << ","
                << customers[id].getLastName() << ","
                << customers[id].getPhone() << ","
                << customers[id].getTotal() << ","
                << customers[id].getVisit();

            for (int i; i < customers[id].getOrderSize(); i++)
                tempF << "," << customers[id].getOrderID(i);
            tempF << std::endl;
        }
        else
            tempF << line << std::endl;
    }

    ifs.close();
    tempF.close();

    if (found) {
        std::remove(this->customerFile.c_str());
        std::rename(this->tempFile.c_str(), this->customerFile.c_str());
    }
    else 
        std::remove(this->tempFile.c_str());

    return;
}

/*void file::saveCustomers(const std::vector<cust::customer>& customers, const std::string& filename) {
    std::ofstream ofs(filename, std::ios::binary);
    if(!ofs){
        //cerr -> means a character error.
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
        return;
    }

    size_t customerCount = customers.size();
    ofs.write(reinterpret_cast<const char*>(&customerCount), customerCount);

    for(const auto&customer: customers)
        customer.serialize(ofs);

    return;
}

std::vector<cust::customer> file::loadCustomers(const std::string& filename){
    size_t i, customerCount = 0;
    std::vector<cust::customer> customers;
    std::ifstream ifs(filename, std::ios::binary);


    if(!ifs){
        //cerr -> means a character error.
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
        return customers;
    }

    ifs.read(reinterpret_cast<char*>(&customerCount), sizeof(customerCount));

    for(i = 0; i < customerCount; i++)
        customers.push_back(cust::customer::deserialize(ifs));

    return customers;
}

void file::saveOrders(const std::unordered_map<int, std::vector<orderInfo::order>>& orders, const std::string& filename){
    size_t orderCount = orders.size(), numOrders = 0;
    std::ofstream ofs(filename, std::ios::binary);
    int customerID = 0;
    /*orderInfo::order customerOrders;

    if(!ofs){
        //cerr -> means a character error.
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
        return;
    }

    ofs.write(reinterpret_cast<const char*>(&orderCount), sizeof(orderCount));

    for(const auto& [customerID, customerOrders] : orders){
        ofs.write(reinterpret_cast<const char*>(&customerID), sizeof(customerID));
    
        numOrders = sizeof(customerOrders);
        ofs.write(reinterpret_cast<const char*>(&numOrders), sizeof(numOrders));
        
        for(const auto&order : customerOrders)
            order.serialize(ofs); 
            
    }
    
    return;
}

std::unordered_map<int, std::vector<orderInfo::order>> file::loadOrders(const std::string& filename){
    int customerID = 0; 
    size_t i, j, orderCount = 0, numOrders = 0;
    std::vector<orderInfo::order> customerOrders;
    std::unordered_map<int, std::vector<orderInfo::order>> orders;
    std::ifstream ifs(filename, std::ios::binary);

    if(!ifs){
        //cerr -> means a character error. 
        std::cerr << "Unable to open file for reading: " << filename << std::endl; 
        return orders; 
    }

    ifs.read(reinterpret_cast<char*>(&orderCount), sizeof(orderCount));

    for(i = 0; i < orderCount; i++){
        ifs.read(reinterpret_cast<char*>(&customerID), sizeof(customerID));

        ifs.read(reinterpret_cast<char*>(&numOrders), sizeof(numOrders));

        for(j = 0; j < numOrders; j++)
            customerOrders.push_back(orderInfo::order::deserialize(ifs));
        orders[customerID] = customerOrders;
    }
    return orders;
}
*/