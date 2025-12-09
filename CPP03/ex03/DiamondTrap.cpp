/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:15 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:49:04 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void){
    _name = "DiamondTrap";
    ClapTrap::_name = _name + "_clap_name";
    _hit = FragTrap::_hit;
    _energy = ScavTrap::_energy;
    _attack = FragTrap::_attack;
    std::cout << "DiamondTrap default constructor called for " << _name << '\n';
}
DiamondTrap::DiamondTrap(std::string name):ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name){
    _name = name;
    ClapTrap::_name = _name + "_clap_name";
    _hit = FragTrap::_hit;
    _energy = ScavTrap::_energy;
    _attack = FragTrap::_attack;
    std::cout << "DiamondTrap constructor called for " << _name << '\n';
}
DiamondTrap::DiamondTrap(const DiamondTrap& copy):ClapTrap(copy), ScavTrap(copy), FragTrap(copy){
    *this = copy;
    std::cout << "DiamondTrap copy constructor called for " << _name << '\n';
}
DiamondTrap::~DiamondTrap(void){
    std::cout << "DiamondTrap destructor called for " << _name << '\n';
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy){
    if (this != &copy){
        _name = copy.getName();
        _hit = copy.getHit();
        _energy = copy.getEnergy();
        _attack = copy.getAttack();
    }
    return *this;
}
void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}
std::string DiamondTrap::getName(void) const{
    return this->_name;
}
void DiamondTrap::whoAmI(void){
    std::cout << "DiamondTrap name: " << _name << ", ClapTrap name: " << ClapTrap::_name << '\n';
}