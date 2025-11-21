#include "../Includes/main.hpp"

std::string intToString(int i){
    std::ostringstream ostr;
    ostr << i;
    return ostr.str();
}

bool stringToInt(std::string str, int *i){
    if(!Contact::isdigitStr(str)){
        std::cout << "Invalid number input\n";
        return false;
    }
    std::istringstream istr(str);
    istr >> *i;
    return true;
}