/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:06:17 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/25 18:01:22 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    public:
        HumanB(std::string name);
        ~HumanB(void);

        void setWeapon(Weapon &weapon);
        void setName(std::string name);
        void attack(void) const;

    private:
        std::string _name;
        Weapon *_weapon;
};

#endif