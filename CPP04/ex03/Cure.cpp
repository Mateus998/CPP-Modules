/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:55 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/12 17:15:49 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria("cure"){}

Cure::Cure(const Cure& c): AMateria(c){}

Cure::~Cure(void){}

Cure& Cure::operator=(const Cure& m){
    (void)m;
    return *this;
}
Cure* Cure::clone() const{
    Cure* clone = new Cure(*this);
    return clone;
}
void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}