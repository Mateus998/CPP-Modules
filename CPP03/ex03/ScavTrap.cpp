#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
    _name = "ScavTrap";
    _hit = 100;
    _attack = 20;
    _energy = 50;
    std::cout << "ScavTrap default constructor called for " << _name << '\n';
}
ScavTrap::ScavTrap(std::string name):ClapTrap(name){
    _name = name;
    _hit = 100;
    _attack = 20;
    _energy = 50;
    std::cout << "ScavTrap constructor called for " << _name << '\n';
}
ScavTrap::ScavTrap(const ScavTrap& copy):ClapTrap(copy){
    *this = copy;
    std::cout << "ScavTrap copy constructor called for " << _name << '\n';
}
ScavTrap::~ScavTrap(void){
    std::cout << "ScavTrap destructor called for " << _name << '\n';
}
ScavTrap& ScavTrap::operator=(const ScavTrap& copy){
    if (this != &copy){
        _name = copy.getName();
        _hit = copy.getHit();
        _energy = copy.getEnergy();
        _attack = copy.getAttack();
    }
    return *this;
}
void ScavTrap::attack(const std::string& target){
    if(!_energy)
        return;
    std::cout << "ScavTrap "<<_name<<" attacks "<<target<<", causing "<<_attack<<" points of damage!\n";
    _energy--;
}
void ScavTrap::guardGate(void){
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n";
}