/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:47 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/12 17:24:15 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type):_type(type){}

AMateria::AMateria(const AMateria& m){
    *this = m;
}

AMateria::AMateria(void):_type(""){}

AMateria::~AMateria(void){}

AMateria& AMateria::operator=(const AMateria& m){
    _type = m.getType();
    return *this;
}

std::string const & AMateria::getType() const{
    return _type;
}

void AMateria::use(ICharacter& target){
    std::cout << "* generic spell casted to " << target.getName() << " *" << std::endl;
}