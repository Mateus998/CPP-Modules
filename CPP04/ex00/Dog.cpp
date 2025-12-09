/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:43:00 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:08 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){
    type = "Dog";
    std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& d):Animal(d){
    *this = d;
    std::cout << "Dog copy constructor called\n";
}

Dog::~Dog(void){
    std::cout << "Dog destructor called\n";
}

Dog& Dog::operator=(const Dog& d){
    type = d.type;
    return *this;
}

void Dog::makeSound(void) const{
    std::cout << type << ": au au au\n";
}

std::string Dog::getType(void) const{
    return type;
}