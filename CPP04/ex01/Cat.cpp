/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:43:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:24 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void){
    std::cout << "Cat default constructor called\n";
    type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& d):Animal(d), _brain(new Brain(*d._brain)){
    std::cout << "Cat copy constructor called\n";
    *this = d;
}

Cat::~Cat(void){
    std::cout << "Cat destructor called\n";
    delete _brain;
}

Brain* Cat::getBrain(void) const{
    return _brain;
}

Cat& Cat::operator=(const Cat& d){
    type = d.type;
    *_brain = *d.getBrain();
    return *this;
}

void Cat::makeSound(void){
    std::cout << type << ": miau miau\n";
}