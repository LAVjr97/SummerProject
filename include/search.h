#ifndef SEARCH_H
#define SEARCH_H

#include "main.h"
#include "customer.h"
#include "order.h"

namespace search{
    class Search{
        public: 
            Search(){
                this->lastAccessedCustoemr = 0;
                this->lastAccessedOrder = 0;
            }
            
            //search customer
            //search order
            //search by phone

            orderInfo::order& searchAlgo(const std::string& entry);
            orderInfo::order& searchName(const std::string& entry);
            orderInfo::order& searchPhone(const std::string& entry);
            orderInfo::order& searchOrder(const std::string& entry);

            //Determining Functions
            bool isNameWithSpace(const std::string& entry);
            bool isName(const std::string& entry);
            bool isPhoneNumber(const std::string& entry);
            bool isOrderID(const std::string& entry);

        private: 
            //last accessed 
            int lastAccessedOrder;
            int lastAccessedCustoemr;

    };

}

#endif
