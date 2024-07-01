//Notes: To clear screen on Unix based os', use "clear", windows, "cls"

#include <string>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include "order.h"
#include <ctime> 


using namespace std;

namespace menu{
    class options{
        public: 
            //Static functions, functions to be used through out run time. 
            static int handleDropOff();
            static int handlePickUp();
            static int handleLookUp();
            static int handleHistory();
            static std::array<std::tuple<int, double>, 8> handleArticles();

            static std::string getDate();

        private: 

    };

    
}



