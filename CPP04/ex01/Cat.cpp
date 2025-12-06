#include "Cat.hpp"

Cat::Cat(void){
    type = "Cat";
    std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& d):Animal(d){
    *this = d;
    std::cout << "Cat copy constructor called\n";
}

Cat::~Cat(void){
    std::cout << "Cat destructor called\n";
}

Cat& Cat::operator=(const Cat& d){
    type = d.type;
    return *this;
}

void Cat::makeSound(void){
    std::cout << type << ": miau miau\n";
}