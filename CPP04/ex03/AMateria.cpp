#include "AMateria.hpp"

AMateria::AMateria(std::string const & type){
    _type = type;
}
AMateria::AMateria(void){
    _type = "default";
}
AMateria::~AMateria(void){}

AMateria& AMateria::operator=(const AMateria& m){
    return *this;
}

std::string const & AMateria::getType() const{
    return _type;
}

void AMateria::use(ICharacter& target){
    return;
}