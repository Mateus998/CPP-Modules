/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:08:00 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/25 18:00:46 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name), _weapon(NULL){
}

HumanB::~HumanB(void){
    return;
}

void HumanB::setWeapon(Weapon &weapon){
    this->_weapon = &weapon;
}

void HumanB::setName(std::string name){
    this->_name = name;
}

void HumanB::attack(void) const{
    std::cout << this->_name
    << " attacks with their "
    << this->_weapon->getType()
    << std::endl;
}