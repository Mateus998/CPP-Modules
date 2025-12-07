#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
    protected:
        std::string type;
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal& a);
        virtual ~WrongAnimal(void);
        WrongAnimal& operator=(const WrongAnimal& a);

        void makeSound(void) const;
};

#endif