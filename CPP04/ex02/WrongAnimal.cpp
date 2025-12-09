/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:35 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:59 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
    std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& a){
    *this = a;
    std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal::~WrongAnimal(void){
    std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a){
    (void)a;
    return *this;
}

void WrongAnimal::makeSound(void) const{
    std::cout << "Generic wrong animal sound\n";
}