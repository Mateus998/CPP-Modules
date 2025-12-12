/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:45:00 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/12 15:58:51 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice(void);
    Ice(const Ice& i);
    ~Ice(void);
    Ice& operator=(const Ice& m);
    Ice* clone() const;
    void use(ICharacter& target);
};

#endif