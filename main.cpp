#include "menuHeader.h"


using namespace std;

int printMenu(void);
int input(int);

int main(){
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
        if(1 == input(option))
            break;
    }
}

int printMenu(){
    cout << "\n---- Cleaning & Alterations ----";
    cout << "\n1) Drop Off\n2) Pick Up\n3) Order Look Up\n4) History\n5) Shut Down\n"; 
    return 0; 
}

int input(int option){
    switch (option){
    case 1:
        menu::options::handleDropOff();
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