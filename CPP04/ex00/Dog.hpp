#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
    public:
        Dog(void);
        Dog(const Dog& d);
        ~Dog(void);
        Dog& operator=(const Dog& d);
        void makeSound(void) const;
        std::string getType(void) const;
};

#endif