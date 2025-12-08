#ifndef CHARACTER_HPP
#define CHARACETER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
    std::string _name;
    AMateria* _inventory[4];
    public:
    Character(void);
    Character(std::string& name);
    Character(Character& c);
    ~Character();
    Character& operator=(const Character& c);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif