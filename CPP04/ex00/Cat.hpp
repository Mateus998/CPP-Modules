#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat(void);
        Cat(const Cat& d);
        ~Cat(void);
        Cat& operator=(const Cat& d);
        void makeSound(void) const;
        std::string getType(void) const;
};

#endif