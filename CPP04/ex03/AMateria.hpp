/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:48 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:48:10 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
std::string _type;

public:
AMateria(std::string const & type);
AMateria(void);
virtual ~AMateria(void);
AMateria& operator=(const AMateria& m);
std::string const & getType() const;
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};

#endif