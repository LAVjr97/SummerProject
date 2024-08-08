#include "../include/order.h"
#include "../include/customer.h"
#include "../include/search.h"

using namespace search;


//all in one search algo

//Customer search functions
std::vector<cust::customer> Search::searchCustAlgo(const std::string& entry, std::vector<cust::customer>& customers){
    std::vector<cust::customer> customer;
    if (isID(entry))
        customer = searchCustID(entry, customers);
    
    else if (isNameWithSpace(entry))
        customer = searchCustName(entry, customers);
    
    else if (isName(entry))
        customer = searchCustLastName(entry, customers);

    return customer;
}

std::vector<cust::customer> Search::searchCustName(const std::string& entry, std::vector<cust::customer>& customers){
    std::vector<cust::customer> customer;
    int i = 0;

    for (i = 0; i < customers.size(); i++) 
        if (entry == customers[i].getName())
            customer.emplace_back(customers[i].getCustomerID(), customers[i].getFirstName(), customers[i].getLastName(), customers[i].getPhone(), customers[i].getVisit(), customer[i].getTotal());

    return customer;
}


std::vector<cust::customer> Search::searchCustLastName(const std::string& entry, std::vector<cust::customer>& customers){
    std::vector<cust::customer> customer;
    int i = 0;

    for (i = 0; i < customers.size(); i++)
        if (entry == customers[i].getLastName())
            customer.emplace_back(customers[i].getCustomerID(), customers[i].getFirstName(), customers[i].getLastName(), customers[i].getPhone(), customers[i].getVisit(), customer[i].getTotal());

    return customer;
}
/*std::vector<cust::customer> Search::searchCustPhone(const std::string& entry, std::vector<cust::customer>& customers) {
    std::vector<cust::customer> customer;
    int i;

    for(i = 0; i < customers.size(); i++)
        if(entry == customers[i].getPhone())
            customer.emplace_back(customers[i].getCustomerID(), customers[i].getFirstName(), customers[i].getLastName(), customers[i].getPhone(), customers[i].getVisit(), customer[i].getTotal());
    
    return customer;
}*/

std::vector<cust::customer> Search::searchCustID(const std::string& entry, std::vector<cust::customer>& customers) {
    std::vector<cust::customer> customer;
    int id = std::stoi(entry), i = 0;

    for (i = 0; i < customers.size(); i++)
        if (id == customers[i].getCustomerID()){
            customer.emplace_back(customers[i].getCustomerID(), customers[i].getFirstName(), customers[i].getLastName(), customers[i].getPhone(), customers[i].getVisit(), customer[i].getTotal());
            break;
        }
    return customer;
}

//Order search functions
std::vector<orderInfo::order> Search::searchOrderAlgo(const std::string& entry, std::vector<orderInfo::order> &orders){
    std::vector<orderInfo::order> order;
    std::cout << "in search Algo";
    
    if (isID(entry)) 
        order = searchOrderID(entry, orders);

    std::cout << "\nleaving SearchAlgo \n";
    return order;
}   

std::vector<orderInfo::order> Search::searchOrderID(const std::string& entry, const std::vector<orderInfo::order> &orders){
    int id = stoi(entry), i, j = 0;
    std::vector<orderInfo::order> order;


    std::cout << "in searchOrder before loop";

    for(i = 0; i < orders.size(); i++){
        std::cout <<"\n" << "in for Loop, i: " << i << " j: " << j << "\n";
        if(orders[i].getOrderID() == id){
            std::cout << "In if statement, i: " << i << " j: " << j << "\n";

            order.emplace_back(orders[i].getCustomerID(), orders[i].getCustomerID(), orders[i].getDetails(), orders[i].getCost());
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
    std::cout << "\nIn isName function \n";
    return std::all_of(entry.begin(), entry.end(), ::isalpha);
}

bool Search::isPhoneNumber(const std::string& entry){
    std::regex phoneRegex(R"((\(\d{3}\) |\d{3}-)?\d{3}-\d{4})");
    return std::regex_match(entry, phoneRegex);
}

bool Search::isID(const std::string& entry){
    std::cout << "in isOrderID";
    return std::all_of(entry.begin(), entry.end(), ::isdigit) && entry.length() <= 7;
}



