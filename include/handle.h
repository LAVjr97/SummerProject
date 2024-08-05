//Notes: To clear screen on Unix based os', use "clear", windows, "cls"
#ifndef HANDLE_H
#define HANDLE_H

#include "../include/main.h"
#include "../include/order.h"
#include "../include/customer.h"
#include "../include/search.h"
#include "file.h"



using namespace std;

namespace menu{
    class options{
        public: 
            //Static functions, functions to be used through out run time. 
            static int handleDropOff(std::vector<orderInfo::order> &orders, std::vector<cust::customer> &customers, fi::File &manager);
            static int handlePickUp(std::vector<orderInfo::order> &orders, std::vector<cust::customer> &customers, fi::File &manager);
            static int handleLookUp(std::vector<orderInfo::order> &orders, std::vector<cust::customer> &customers, fi::File &manager);
            static int handleHistory(std::vector<orderInfo::order> &orders, std::vector<cust::customer> &customers, fi::File &manager);
            static std::array<std::tuple<int, double>, 8> handleArticles();

        private: 

    };

    
}

#endif // !MENU_HEADER_H