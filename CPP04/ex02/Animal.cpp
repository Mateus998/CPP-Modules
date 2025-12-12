/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:11 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/12 11:41:58 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(void){
    std::cout << "Animal default constructor called\n";
}

AAnimal::AAnimal(const AAnimal& a){
    std::cout << "Animal copy constructor called\n";
    *this = a;
}

AAnimal::~AAnimal(void){
    std::cout << "Animal destructor called\n";
}

AAnimal& AAnimal::operator=(const AAnimal& a){
    (void)a;
    return *this;
}