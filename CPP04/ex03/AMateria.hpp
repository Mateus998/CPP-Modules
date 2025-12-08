#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
std::string _type;

public:
AMateria(std::string const & type);
AMateria(void);
virtual ~AMateria(void);
AMateria& operator=(const AMateria& m);
std::string const & getType() const;
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};

#endif