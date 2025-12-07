#include "Brain.hpp"

Brain::Brain(void){
    std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& d){
    std::cout << "Brain copy constructor called\n";
    *this = d;
}

Brain::~Brain(void){
    std::cout <<"Brain destructor called\n";
}

Brain& Brain::operator=(const Brain& d){
    if (this != &d){
        for(int i = 0; i < 100; i++){
            ideas[i] = d.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(const std::string& ideas){
    for(int i = 0; i < 100; i++){
        if(this->ideas->empty())
            this->ideas[i] = ideas;
    }
}