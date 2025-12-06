#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat(void);
        Cat(const Cat& d);
        ~Cat(void);
        Cat& operator=(const Cat& d);
        void makeSound(void);
};

#endif