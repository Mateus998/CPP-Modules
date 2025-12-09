/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:43:29 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:18 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void){
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal& a){
    std::cout << "Animal copy constructor called\n";
    *this = a;
}

Animal::~Animal(void){
    std::cout << "Animal destructor called\n";
}

Animal& Animal::operator=(const Animal& a){
    (void)a;
    return *this;
}

void Animal::makeSound(void){
    std::cout << "Generic animal sound\n";
}