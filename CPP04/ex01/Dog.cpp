/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:43:49 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:29 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){
    std::cout << "Dog default constructor called\n";
    type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& d):Animal(d), _brain(new Brain(*d._brain)){
    std::cout << "Dog copy constructor called\n";
    *this = d;
}

Dog::~Dog(void){
    std::cout << "Dog destructor called\n";
    delete _brain;
}

Brain* Dog::getBrain(void)const{
    return _brain;
}

Dog& Dog::operator=(const Dog& d){
    type = d.type;
    *_brain = *d._brain;
    return *this;
}

void Dog::makeSound(void){
    std::cout << type << ": au au au\n";
}