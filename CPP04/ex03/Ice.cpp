/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:59 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/12 17:35:40 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria("ice"){}

Ice::Ice(const Ice& i): AMateria(i){}

Ice::~Ice(void){}

Ice& Ice::operator=(const Ice& m){
    (void)m;
    return *this;
}

Ice* Ice::clone() const{
    Ice* clone = new Ice(*this);
    return clone;
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}