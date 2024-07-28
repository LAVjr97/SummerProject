#include "../include/search.h"
#include "../include/order.h"
#include "../include/customer.h"

using namespace search;

orderInfo::order& searchAlgo(const std::string& entry){
    std::tuple<cust::customer, orderInfo::order> tup;
    if(isNameWithSpace(entry)){
        order = searchName(entry);
    }
}

orderInfo::order& searchName(const std::string& entry){

}
orderInfo::order& searchPhone(const std::string& entry){

}
orderInfo::order& searchOrder(const std::string& entry){

}

//Determining Functions
bool isNameWithSpace(const std::string& entry){
    size_t spacePos = entry.find(' ');
    if (spacePos != std::string::npos && spacePos != 0 && spacePos != entry.length() - 1) { //basically the space makes sure that the space isnt at the start or end
        std::string firstName = entry.substr(0, spacePos);
        std::string lastName = entry.substr(spacePos + 1);
        return std::all_of(firstName.begin(), firstName.end(), ::isalpha) && std::all_of(lastName.begin(), lastName.end(), ::isalpha); //makes sure that both the first and last name are both 
    }
    return false;
}

bool isName(const std::string& entry){
    return std::all_of(entry.begin(), entry.end(), ::isalpha);
}
bool isPhoneNumber(const std::string& entry){
    std::regex phoneRegex(R"((\(\d{3}\) |\d{3}-)?\d{3}-\d{4})");
    return std::regex_match(entry, phoneRegex);
}

bool isOrderID(const std::string& entry){
    return std::all_of(entry.begin(), entry.end(), ::isdigit) && entry.length() <= 7;
}



