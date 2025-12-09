/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:22 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:49:01 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void){
    _name = "FragTrap";
    _hit = 100;
    _attack = 30;
    _energy = 100;
    std::cout << "FragTrap default constructor called for " << _name << '\n';
}
FragTrap::FragTrap(std::string name):ClapTrap(name){
    _name = name;
    _hit = 100;
    _attack = 30;
    _energy = 100;
    std::cout << "FragTrap constructor called for " << _name << '\n';
}
FragTrap::FragTrap(const FragTrap& copy):ClapTrap(copy){
    *this = copy;
    std::cout << "FragTrap copy constructor called for " << _name << '\n';
}
FragTrap::~FragTrap(void){
    std::cout << "FragTrap destructor called for " << _name << '\n';
}
FragTrap& FragTrap::operator=(const FragTrap& copy){
    if (this != &copy){
        _name = copy.getName();
        _hit = copy.getHit();
        _energy = copy.getEnergy();
        _attack = copy.getAttack();
    }
    return *this;
}
void FragTrap::highFivesGuys(void){
    std::cout << "FragTrap " << _name << " is requesting a high-five.\n";
}