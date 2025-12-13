/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:50 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/12 19:10:12 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int Character::_disIncrement = 5;

Character::Character(void):_name(""), _discart(NULL), _discartCount(0){
    for (int i = 0; i < 4; i++){
        _inventory[i] = NULL;
    }
}

Character::Character(const std::string& name):_name(name), _discart(NULL), _discartCount(0){
    for (int i = 0; i < 4; i++){
        _inventory[i] = NULL;
    }
}

Character::Character(const Character& c){
    _name = c.getName();
    for(int i = 0; i < 4; i++){
        _inventory[i] = c._inventory[i]->clone();
    }
    _discartCount = c._discartCount;
    for(int i = 0; i < _discartCount; i++){
        _discart[i] = c._discart[i]->clone();
    }
}

Character::~Character(){
    for(int i = 0; i < 4; i++){
        delete _inventory[i];
    }
    for(int i = 0; i < _discartCount; i++){
        delete _discart[i];
    }
    delete[] _discart;
}

Character& Character::operator=(const Character& c){
    if(this != &c){
        _name = c.getName();
        for(int i = 0; i < 4; i++){
            delete _inventory[i];
            _inventory[i] = c._inventory[i]->clone();
        }

        _discartCount = c._discartCount;
        for(int i = 0; i < _discartCount; i++){
            delete _discart[i];
            _discart[i] = c._discart[i]->clone();
        }
    }
    return *this;
}

std::string const & Character::getName() const{
    return _name;
}

void Character::equip(AMateria* m){
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++){
        if (!_inventory[i]){
            _inventory[i] = m;
            std::cout << m->getType() << " Materia equiped on slot " << i << std::endl;
            return;
        }
    }
    std::cout << this->getName() << "'s inventory is full" << std::endl;
}

void Character::unequip(int idx){
    if (idx < 0 || idx > 4 || !_inventory[idx])
        return;
        
    if(_discartCount % _disIncrement == 0){
        AMateria** newDiscart = new AMateria*[_discartCount + _disIncrement]();
        
        for (int i = 0; i < _discartCount; i++){
            newDiscart[i] = _discart[i];
        }
        
        delete[] _discart;    
        _discart = newDiscart;        
    }
    _discart[_discartCount++] = _inventory[idx];
    std::cout << this->getName() << " enequiped " << _inventory[idx]->getType() << " Materia of slot " << idx << std::endl;
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
    if (idx >= 0 && idx < 4){
        if(!_inventory[idx])
            std::cout << this->getName() << "'s inventory slot is empty" << idx << std::endl;
        else{
            std::cout << this->getName() << " ";
            _inventory[idx]->use(target);
        }
    }
}