#include "Dog.hpp"

Dog::Dog(void){
    type = "Dog";
    std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& d):Animal(d){
    *this = d;
    std::cout << "Dog copy constructor called\n";
}

Dog::~Dog(void){
    std::cout << "Dog destructor called\n";
}

Dog& Dog::operator=(const Dog& d){
    type = d.type;
    return *this;
}

void Dog::makeSound(void){
    std::cout << type << ": au au au\n";
}