#include "Animal.hpp"

Animal::Animal(void){
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& a){
    *this = a;
    std::cout << "Animal copy constructor called\n";
}

Animal::~Animal(void){
    std::cout << "Animal destructor called\n";
}

Animal& Animal::operator=(const Animal& a){
    (void)a;
    return *this;
}

void Animal::makeSound(void) const{
    std::cout << "Generic animal sound\n";
}

std::string Animal::getType(void) const{
    return type;
}