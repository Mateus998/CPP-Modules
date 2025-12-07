#include "Cat.hpp"

Cat::Cat(void){
    std::cout << "Cat default constructor called\n";
    type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& d):AAnimal(d), _brain(new Brain(*d._brain)){
    std::cout << "Cat copy constructor called\n";
    *this = d;
}

Cat::~Cat(void){
    std::cout << "Cat destructor called\n";
    delete _brain;
}

Brain* Cat::getBrain(void) const{
    return _brain;
}

Cat& Cat::operator=(const Cat& d){
    type = d.type;
    *_brain = *d.getBrain();
    return *this;
}

void Cat::makeSound(void){
    std::cout << type << ": miau miau\n";
}