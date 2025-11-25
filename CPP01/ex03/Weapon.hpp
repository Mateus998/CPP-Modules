/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:33:31 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/25 18:08:10 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{
    public:
        Weapon(const std::string &type);
        ~Weapon(void);

        const std::string& getType(void) const;
        void setType(const std::string &type);
        
    private:
        std::string _type;
};

#endif