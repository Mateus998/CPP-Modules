/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:57 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/12 15:36:28 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
    Cure(void);
    Cure(const Cure& c);
    ~Cure(void);
    Cure& operator=(const Cure& m);
    Cure* clone() const;
    void use(ICharacter& target);
};

#endif