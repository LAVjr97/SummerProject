/*  file.h
    Used to save customer information to an unordered map and 
 */

#ifndef FILE_H
#define FILE_H

#include "main.h"

#include "customer.h"
#include "order.h"

namespace fi{
    class file{
        public: 
            //Customers
            static void saveCustomers(const std::vector<cust::customer>& customers, const std::string& filename);
            static std::vector<cust::customer> loadCustomers(const std::string& filename);

            //Orders  
            static void saveOrders(const std::unordered_map<int, std::vector<orderInfo::order>>& orders, const std::string& filename);
            static std::unordered_map<int, std::vector<orderInfo::order>> loadOrders(const std::string& filename); 
    };

}

#endif
