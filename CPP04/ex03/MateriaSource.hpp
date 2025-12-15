/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:06:47 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/15 14:06:48 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
private:
   AMateria* _templates[4];
public:
    MateriaSource(void);
    ~MateriaSource(void);
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif