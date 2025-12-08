#include "Ice.hpp"

Ice::Ice(void){
    _type = "ice";
}
Ice::~Ice(void){}
Ice& Ice::operator=(const Ice& m){
    return *this;
}
Ice* Ice::clone() const{
    Ice* clone = new Ice(*this);
    return clone;
}
void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at <name> *";
}