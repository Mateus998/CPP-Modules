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
}

Character::~Character(){
    for(int i = 0; i < 4; i++){
        delete _inventory[i];
    }
    for(int i = 0; i < _discartCount; i++){
        delete _discart[i];
    }
}

Character& Character::operator=(const Character& c){
    if(this != &c){
        for(int i = 0; i < 4; i++){
            delete _inventory[i];
        }
        for(int i = 0; i < _discartCount; i++){
            delete _discart[i];
        }
        
        _name = c.getName();
        for(int i = 0; i < 4; i++){
            _inventory[i] = c._inventory[i]->clone();
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
            break;
        }
        else if(i == 3){
            std::cout << "Full inventory" << std::endl;
            return;
        }
    }
    for (int i = 0; i < _discartCount; i++){
        if(_discart[i] == m){
            for(int j = i; j < _discartCount - 1; i++){
                _discart[j] = _discart[j + 1];
            }
            _discart[--_discartCount] = NULL;
            return;
        }
    }
}

void Character::unequip(int idx){
    if (idx < 0 || idx > 4 || !_inventory[idx])
        return;
        
    if(_discartCount % 10 == 0){
        AMateria** newDiscart = new AMateria*[_discartCount + 10]();
        
        for (int i = 0; i < _discartCount; i++){
            newDiscart[i] = _discart[i];
        }
        
        delete[] _discart;    
        _discart = newDiscart;        
    }
    
    for (int i = 0; i <= _discartCount; i++){
        if(!_discart[i])
            _discart[i] = _inventory[idx];
    }
    _discartCount++;
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
    if (idx > 0 && idx < 4){
        if(!_inventory[idx])
            std::cout << "Empty inventory slot" << std::endl;
        else
            _inventory[idx]->use(target);
    }
}