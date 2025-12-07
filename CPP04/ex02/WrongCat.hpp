#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
        WrongCat(void);
        WrongCat(const WrongCat& d);
        ~WrongCat(void);
        WrongCat& operator=(const WrongCat& d);
        void makeSound(void) const;
        std::string getType(void) const;
};

#endif