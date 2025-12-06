#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
    std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& a){
    *this = a;
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal::~WrongAnimal(void){
    std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a){
    (void)a;
    return *this;
}

void WrongAnimal::makeSound(void) const{
    std::cout << "Generic wrong animal sound\n";
}