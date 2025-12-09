/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:43:21 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:15 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void){
    type = "WrongCat";
    std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat& d):WrongAnimal(d){
    *this = d;
    std::cout << "WrongCat copy constructor called\n";
}

WrongCat::~WrongCat(void){
    std::cout << "WrongCat destructor called\n";
}

WrongCat& WrongCat::operator=(const WrongCat& d){
    type = d.type;
    return *this;
}

void WrongCat::makeSound(void) const{
    std::cout << type << ": miau miau\n";
}

std::string WrongCat::getType(void) const{
    return type;
}