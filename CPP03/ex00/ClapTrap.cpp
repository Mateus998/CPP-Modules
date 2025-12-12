/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:34:11 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/12 16:38:09 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void){
    _name = "ClapTrap";
    _hit = 10;
    _attack = 0;
    _energy = 10;
    std::cout << "Default constructor called for " << _name << '\n';
}

ClapTrap::ClapTrap(const std::string& name):_name(name){
    _hit = 10;
    _attack = 0;
    _energy = 10;
    std::cout << "Constructor called for " << _name << '\n';
}

ClapTrap::ClapTrap(const ClapTrap& copy){
    *this = copy;
    std::cout << "Copy constructor called for " << _name << '\n';
}

ClapTrap::~ClapTrap(void){
    std::cout << "Destructor called for " << _name << '\n';
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy){
    if (this != &copy){
        _name = copy.getName();
        _hit = copy.getHit();
        _energy = copy.getEnergy();
        _attack = copy.getAttack();
    }
    return *this;
}

void ClapTrap::attack(const std::string& target){
    if(!_energy)
        return;
    std::cout << "ClapTrap "<<_name<<" attacks "<<target<<", causing "<<_attack<<" points of damage!\n";
    _energy--;
}
void ClapTrap::takeDamage(unsigned int amount){
    _hit -= amount;
    std::cout << "ClapTrap "<<_name<<" took "<<amount<<" points of damage!\n";
}
void ClapTrap::beRepaired(unsigned int amount){
    if(!_energy)
        return;
    _hit += amount;
    std::cout << "ClapTrap "<<_name<<" repaired "<<amount<<" points of health!\n";
    _energy--;
}

std::string ClapTrap::getName(void) const{
    return _name;
}
int ClapTrap::getHit(void) const{
    return _hit;
}
int ClapTrap::getEnergy(void) const{
    return _energy;
}
int ClapTrap::getAttack(void) const{
    return _attack;
}