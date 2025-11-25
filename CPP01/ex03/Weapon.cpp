/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:33:28 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/25 18:08:16 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type): _type(type){
}

Weapon::~Weapon(void){
    return;
}

const std::string& Weapon::getType(void) const{
    return this->_type;
}

void Weapon::setType(const std::string &type){
    this->_type = type;
}