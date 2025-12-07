#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
    public:
        Cat(void);
        Cat(const Cat& d);
        ~Cat(void);
        Cat& operator=(const Cat& d);
        void makeSound(void);
        Brain* getBrain(void) const;
    private:
        Brain* _brain;
};

#endif