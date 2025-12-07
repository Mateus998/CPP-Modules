#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal{
    protected:
        std::string type;
    public:
        AAnimal(void);
        AAnimal(const AAnimal& a);
        virtual ~AAnimal(void) = 0;
        AAnimal& operator=(const AAnimal& a);

        virtual void makeSound(void);
};

#endif