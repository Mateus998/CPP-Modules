#include "Cure.hpp"

Cure::Cure(void){
    _type = "cure";
}
Cure::~Cure(void){}
Cure& Cure::operator=(const Cure& m){
    return *this;
}
Cure* Cure::clone() const{
    Cure* clone = new Cure(*this);
    return clone;
}
void Cure::use(ICharacter& target){
    std::cout << "* heals <name>’s wounds *";
}