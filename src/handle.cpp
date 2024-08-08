#include "../include/handle.h"



//To clear the screen, windows uses "cls", mac/linux uses "clear" 
#define screen "cls"

using namespace menu;

int options::handleDropOff(std::vector<orderInfo::order> &orders, std::vector<cust::customer> &customers, fi::File &manager) {
    system(screen);
    cout << "\nhandleDropOff";

    //Initialize variables
    std::string date, time, firstName, lastName, firstTime, number; 
    std::array<std::tuple<int, double>, 8> articles; 
    double cost = 0.99; 
    int customerID = 0; 
    search::Search search;
    std::vector<cust::customer> customer;

    //Customer Info
    cout << "\nIs this a first-time cusomter? <Yes/No>\n";
    cin >> firstTime;
    cout << "\nCustomer First Name:\n";
    cin >> firstName;
    cout << "\nCusotmer Last Name:\n";
    cin >> lastName;


    //Handle First time customer
    if(firstTime == "Yes" || firstTime == "yes" || firstTime == "y" || firstTime == "Y"){
        cout << "\nCustomer Phone Number?\n";
        cin >> number;
        
        //calculate customerID
        //auto endIt = customers.end(); //last index
        //customerID = std::distance(customers.begin(), endIt); //calculates the distance between the first and last index and subtracts 1 to return the last index, i.e. newest customer ID
        customerID = customers.size();
        cout << customerID;
           
        customers.emplace_back(customerID, firstName, lastName, number);
        std::cout << std::endl << "before going to SaveCustomers()" << std::endl;
        manager.saveCustomers(customers[customerID]); 
        cout << "\n" << customers[customerID].getCustomerID(); 
    }
    //Already a pre-existing customer
    else {
        customer = search.searchCustAlgo(lastName, customers);

    }
    articles = handleArticles(); 


    int orderID = orders.size(); 
    cout << orderID;
    //orderInfo::order* orderA = new orderInfo::order(orderID, firstName, lastName, customerID, dropOff, pickUp, articles);
    orders.emplace_back(orderID, customerID, articles);
    customers[customerID].setLatestOrder(orderID);

    manager.saveOrders(orders[orderID]);
    cout << "\n" << orders[orderID].getOrderID();
    
    //cout << "\n" << orderA->getCustomerID();

    //orders.emplace(firstName, lastName, customerID, dropOff, pickUp, articles);



    //Have the customer 
    //save function before returning to main menu, there will be an auto save feature and a manual save before exiting to main menu. 
    return 0;
}

int options::handlePickUp(std::vector<orderInfo::order> &orders, std::vector<cust::customer> &customers, fi::File &manager) {
    std::string entry;
    search::Search search;
    std::vector<orderInfo::order> order;
    int i;
    system(screen);
    cout << "\nhandlePickUp";
    cout << "\nWhat is the name, last name or order ID that belongs to the order? \n";
    cin >> entry;
    
    order = search.searchOrderAlgo(entry, orders);
    std::cout << "\nAfter SearchAlgo\n";
    for(i = 0; i < order.size(); i++){ 
        //std::cout << "\n" << order[i].getCustomerID() << "\n";
        std::cout << std::endl << customers[i].getName() << std::endl;
        //std::cout << "\n" << order[i].getName() << "\n";

        //std::cout << std::endl << order[i].pickUp->getDate_Time() << std::endl;

    }
    return 0;
}

int options::handleLookUp(std::vector<orderInfo::order> &orders, std::vector<cust::customer> &customers, fi::File &manager) {
    system(screen);
    cout << "\nhandleLookUp";
    return 0;
}

int options::handleHistory(std::vector<orderInfo::order> &orders, std::vector<cust::customer> &customers, fi::File &manager) {
    system(screen);
    cout << "\nhandleDropOff";
    return 0;
}

//Creates a menu from where the user selects a piece of clothing and then inputs the number of pieces of that particular clothing 
std::array<std::tuple<int, double>, 8> options::handleArticles() { 
    //[0]: Shirts, [1]: Pants, [2]:Sweaters, [3]:Coats, [4]:Blouses, [5]:2pc Suit, [6]:Jacket, [7]:Vest 
    std::array<std::tuple<int, double>, 8> articles; 
    int article, n;

    while(true){
        //system(screen);
        cout << "\nEnter article number (or '0' to go save and return):\n1) Shirts\n2) Pants\n3) Sweaters\n4) Coats\n5) Blouses\n6) 2pc Suit\n7) Jackets\n7) Vest\n";
        cin >> article;

        switch(article){
            case 1:
                cout << "\nNumber of Shirt(s)?\n";
                cin >> n; 
                articles[0] = std::make_tuple(n, 4.99);
                break;

            case 2: 
                cout << "\nNumber of Pant(s)?\n";
                cin >> n; 
                articles[1] = std::make_tuple(n, 4.99);
                break;

            case 3: 
                cout << "\nNumber of Sweater(s)?\n";
                cin >> n; 
                articles[2] = std::make_tuple(n, 5.99);
                break;

            case 4: 
                cout << "\nNumber of Coat(s)?\n";
                cin >> n; 
                articles[3] = std::make_tuple(n, 6.99);
                break;

            case 5: 
                cout << "\nNumber of Blouse(s)?\n";
                cin >> n; 
                articles[3] = std::make_tuple(n, 4.50);
                break;

            case 6: 
                cout << "\nNumber of 2pc Suit(s)?\n";
                cin >> n; 
                articles[4] = std::make_tuple(n, 12.99);
                break;

            case 7: 
                cout << "\nNumber of Jacket(s)?\n";
                cin >> n; 
                articles[4] = std::make_tuple(n, 6.99);
                break;

            case 8: 
                cout << "\nNumber of Vest(s)?\n";
                cin >> n; 
                articles[4] = std::make_tuple(n, 3.99);
                break;

            case 0: 
                return articles; 
            default: 
                continue;
        }
    }
    return articles;
}

//Returns the current date and time, Foramatted: mm/dd/yy hh:mm <am/pm>
