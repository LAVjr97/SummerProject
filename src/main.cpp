#include "../include/handle.h"
#include "../include/order.h"
#include "../include/customer.h"


using namespace std;

int printMenu(void);
int input(int option, vector<cust::customer> &customers, unordered_map<int, orderInfo::order> &orders);

int main(){

    vector<cust::customer> customers;
    unordered_map<int, orderInfo::order> orders;

    /*
    // Example: Add a new customer
    customers.emplace_back(1, "Alice Smith", "555-1234", 5, 250.00);
    customers.emplace_back(2, "Bob Johnson", "555-5678", 10, 600.00);
    
    // Example: Add new orders
    orders[1].emplace_back(1, 1, "Alice Smith", "2023-06-25", "2023-07-01", std::make_tuple(3, 2), 50.00);
    orders[2].emplace_back(2, 2, "Bob Johnson", "2023-06-26", "2023-07-02", std::make_tuple(5, 1), 60.00);

    // Save data to binary files
    FileManager::saveCustomers(customers, "customers.bin");
    FileManager::saveOrders(orders, "orders.bin");

    // Load data from binary files
    customers = FileManager::loadCustomers("customers.bin");
    orders = FileManager::loadOrders("orders.bin");
s
    // Display loaded customers
    std::cout << "Loaded Customers:" << std::endl;
    for (const auto& customer : customers){
        std::cout << customer.getId() << ": " << customer.getFirstName() << ", " << customer.getPhone() 
                  << ", Total Visits: " << customer.getTotalVisits() 
                  << ", Total Spent: $" << customer.getTotalSpent() << std::endl; 
    }

    // Display loaded orders
    std::cout << "Loaded Orders:" << std::endl;
    for (const auto& [customerId, customerOrders] : orders) {
        std::cout << "Customer ID: " << customerId << std::endl;
        for (const auto& order : customerOrders) {
            std::cout << "  Order ID: " << order.getOrderId() 
                      << ", Drop Off: " << order.getDropOffDate() 
                      << ", Pick Up: " << order.getPickUpDate() 
                      << ", Pieces (Pants, Shirts): (" << std::get<0>(order.getPieces()) 
                      << ", " << std::get<1>(order.getPieces()) << ")"
                      << ", Cost: $" << order.getCost() << std::endl;
        }
    }

    return 0;
  
    */


    int option = 0;
    while(true){
        printMenu();
        
        cin >> option; 
        if(cin.fail() || option < 1 || option > 5){ 
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Invalid choice. Please enter a number between 1 and 5.\n"; 
            continue; 
        } 
        if(1 == input(option, customers, orders)) 
            break;
    }
}

int printMenu(){
    cout << "\n---- Cleaning & Alterations ----";
    cout << "\n1) Drop Off\n2) Pick Up\n3) Order Look Up\n4) History\n5) Shut Down\n"; 
    return 0; 
}

int input(int option, vector<cust::customer> &customers, unordered_map<int, orderInfo::order> &orders){
    switch (option){
    case 1: 
        menu::options::handleDropOff(orders, customers);
        break;
    case 2: 
        menu::options::handlePickUp();
        break;
    case 3: 
        menu::options::handleLookUp();
        break;
    case 4:
        menu::options::handleHistory();
        break;
    case 5:
        return 1;
    default:
        break;
    }
    
    return 0;
}