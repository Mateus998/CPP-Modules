/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:58:04 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/25 17:51:51 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon), _name(name){
    
}

HumanA::~HumanA(void){
    return;
}

void HumanA::attack(void) const{
    std::cout << this->_name
    << " attacks with their "
    << this->_weapon.getType()
    << std::endl;
}