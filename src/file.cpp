#include "file.h"

using namespace fi;

void file::saveCustomers(const std::vector<cust::customer>& customers, const std::string& filename){
    std::ofstream ofs(filename, std::ios::binary);
    if(!ofs){
        //cerr -> means a character error.
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
        return;
    }
}

std::vector<cust::customer> file::loadCustomers(const std::string& filename){

}

void file::saveOrders(const std::unordered_map<int, std::vector<orderInfo::order>>& orders, const std::string& filename){

}

std::unordered_map<int, std::vector<orderInfo::order>> file::loadOrders(const std::string& filename){

}
