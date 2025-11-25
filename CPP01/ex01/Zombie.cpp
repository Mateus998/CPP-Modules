/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:16:48 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/25 12:53:08 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name){
    this->_name = name;
}

Zombie::Zombie(void){
    return;
}

Zombie::~Zombie(void){
    std::cout << this->_name << " was killed\n";
}

void Zombie::announce(void){
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName(std::string name){
    this->_name = name;
}

