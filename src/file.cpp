#include "file.h"

using namespace fi;

void file::saveCustomers(const std::vector<cust::customer>& customers, const std::string& filename){
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
    size_t i, customerCount;
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
    size_t orderCount = orders.size(), numOrders;    
    std::ofstream ofs(filename, std::ios::binary);

    if(!ofs){
        //cerr -> means a character error. 
        std::cerr << "Unable to open file for writing: " << filename << std::endl; 
        return; 
    }

    ofs.write(reinterpret_cast<const char*>(&orderCount), sizeof(orderCount));

    for(const auto& [customerID, customerOrders] : orders){
        ofs.write(reinterpret_cast<const char*>(&customerID), sizeof(customerID));
    
        numOrders = customerOrders.size();
        ofs.write(reinterpret_cast<const char*>(&numOrders), sizeof(numOrders));
        
        for(const auto&order : customerOrders)
            order.serialize(ofs);
    }

    return;
}

std::unordered_map<int, std::vector<orderInfo::order>> file::loadOrders(const std::string& filename){
    int customerID; 
    size_t i, j, orderCount, numOrders;
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
