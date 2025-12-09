/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:52 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:48:12 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACETER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    private:
    std::string _name;
    AMateria* _inventory[4];
    public:
    Character(void);
    Character(std::string& name);
    Character(Character& c);
    ~Character();
    Character& operator=(const Character& c);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
};

#endif