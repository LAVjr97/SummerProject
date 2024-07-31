#include "../include/order.h"
#include "../include/customer.h"
#include "../include/search.h"

using namespace search;

std::vector<orderInfo::order> Search::searchAlgo(const std::string& entry, std::vector<orderInfo::order> &orders){
    std::vector<orderInfo::order> order;
    std::cout << "in search Algo";
    
    if (isOrderID(entry)) {
        order = searchOrder(entry, orders);
    }
    
    else if(isNameWithSpace(entry)){
        order = searchName(entry, orders);
    }

    else if(isName(entry)){
        order = searchLastName(entry, orders);
    }

    /*else if (this->isPhoneNumber(entry)) {
        order = this->searchPhone(entry, orders);
    }*/
    std::cout << "\nleaving SearchAlgo \n";
    return order;
}   

std::vector<orderInfo::order> Search::searchName(const std::string& entry, const std::vector<orderInfo::order> &orders){
    std::vector<orderInfo::order> order;
    int i, j = 0;
    

    for(i = 0; i < orders.size(); i++){
        if(orders[i].getName() == entry){
            order.emplace_back(orders[i].getCustomerID(), orders[i].getFirstName(), orders[i].getLastName(), orders[i].getCustomerID(), orders[i].getDropOffDate(), orders[i].getPickUpDate(), orders[i].getDetails(), orders[i].getCost());
        }
    } 

    return order;
}

std::vector<orderInfo::order> Search::searchLastName(const std::string& entry, const std::vector<orderInfo::order> &orders){
    std::vector<orderInfo::order> order;
    int i, j = 0;

    for(i = 0; i < orders.size(); i++){
        if(orders[i].getLastName() == entry){
            order.emplace_back(orders[i].getCustomerID(), orders[i].getFirstName(), orders[i].getLastName(), orders[i].getCustomerID(), orders[i].getDropOffDate(), orders[i].getPickUpDate(), orders[i].getDetails(), orders[i].getCost());
        }
    }

    return order;
}
//std::vector<orderInfo::order> Search::searchPhone(const std::string& entry, const std::vector<orderInfo::order> &orders){
//    std::vector<orderInfo::order> orders;

//}

std::vector<orderInfo::order> Search::searchOrder(const std::string& entry, const std::vector<orderInfo::order> &orders){
    int id = stoi(entry), i, j = 0;
    std::vector<orderInfo::order> order;


    std::cout << "in searchOrder before loop";

    for(i = 0; i < orders.size(); i++){
        std::cout <<"\n" << "in for Loop, i: " << i << " j: " << j << "\n";
        if(orders[i].getOrderID() == id){
            std::cout << "In if statement, i: " << i << " j: " << j << "\n";

            order.emplace_back(orders[i].getCustomerID(), orders[i].getFirstName(), orders[i].getLastName(), orders[i].getCustomerID(), orders[i].getDropOffDate(), orders[i].getPickUpDate(), orders[i].getDetails(), orders[i].getCost());
            break;
        }
    }
    std::cout << "\nafter loop SearchOrder\n";
    return order;
}

//Determining Functions
bool Search::isNameWithSpace(const std::string& entry){
    //
    size_t spacePos = entry.find(' ');
    if (spacePos != std::string::npos && spacePos != 0 && spacePos != entry.length() - 1) { //basically the space makes sure that the space isnt at the start or end
        std::string firstName = entry.substr(0, spacePos);
        std::string lastName = entry.substr(spacePos + 1);
        return std::all_of(firstName.begin(), firstName.end(), ::isalpha) && std::all_of(lastName.begin(), lastName.end(), ::isalpha); //makes sure that both the first and last name are both 
    }
    return false;
}

bool Search::isName(const std::string& entry){
    return std::all_of(entry.begin(), entry.end(), ::isalpha);
}

bool Search::isPhoneNumber(const std::string& entry){
    std::regex phoneRegex(R"((\(\d{3}\) |\d{3}-)?\d{3}-\d{4})");
    return std::regex_match(entry, phoneRegex);
}

bool Search::isOrderID(const std::string& entry){
    std::cout << "in isOrderID";
    return std::all_of(entry.begin(), entry.end(), ::isdigit) && entry.length() <= 7;
}



