#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
    private:
        std::string _name;
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& copy);
        ~DiamondTrap(void);
        DiamondTrap& operator=(const DiamondTrap& copy);
        void attack(const std::string& target);
        std::string getName(void) const;
        void whoAmI(void);
};

#endif