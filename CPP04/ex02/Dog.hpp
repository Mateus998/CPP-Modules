#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
    public:
        Dog(void);
        Dog(const Dog& d);
        ~Dog(void);
        Dog& operator=(const Dog& d);
        void makeSound(void);
        Brain* getBrain(void) const;
    private:
        Brain* _brain;
};

#endif