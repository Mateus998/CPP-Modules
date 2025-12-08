#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
Cure(void);
~Cure(void);
Cure& operator=(const Cure& m);
Cure* clone() const;
void use(ICharacter& target);
};

#endif