/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:06:52 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/15 14:06:53 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void){
    for (int i = 0; i < 4; i++){
        _templates[i] = NULL;
    }
}

MateriaSource::~MateriaSource(void){
    for (int i = 0; i < 4; i++){
        delete _templates[i];
    }
}

void MateriaSource::learnMateria(AMateria* m){
    if (!m)
        return;
    for (int i = 0; i < 4; i++){
        if(_templates[i] == NULL){
            _templates[i] = m->clone();
            std::cout << "New " << m->getType() << " Materia learned on slot " << i << std::endl;
            break;
        }
    }
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++){
        if(_templates[i] != NULL && _templates[i]->getType() == type){
            return _templates[i]->clone();
        }
    }
    std::cout << type << " Materia doesn't exist" << std::endl;
    return 0;
}