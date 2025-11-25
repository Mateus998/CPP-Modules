/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:58:00 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/25 17:48:10 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);

        void attack(void) const;

    private:
        Weapon &_weapon;
        std::string _name;
};

#endif