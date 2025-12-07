#include "Animal.hpp"

AAnimal::AAnimal(void){
    std::cout << "Animal default constructor called\n";
}

AAnimal::AAnimal(const AAnimal& a){
    std::cout << "Animal copy constructor called\n";
    *this = a;
}

AAnimal::~AAnimal(void){
    std::cout << "Animal destructor called\n";
}

AAnimal& AAnimal::operator=(const AAnimal& a){
    (void)a;
    return *this;
}

void AAnimal::makeSound(void){
    std::cout << "Generic animal sound\n";
}