/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:47 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:48:07 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type){
    _type = type;
}
AMateria::AMateria(void){
    _type = "default";
}
AMateria::~AMateria(void){}

AMateria& AMateria::operator=(const AMateria& m){
    return *this;
}

std::string const & AMateria::getType() const{
    return _type;
}

void AMateria::use(ICharacter& target){
    return;
}