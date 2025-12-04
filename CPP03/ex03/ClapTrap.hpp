/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:25:48 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/03 18:40:40 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    protected:
        std::string _name;
        int _hit;
        int _energy;
        int _attack;
    
    public:
        ClapTrap(void);
        ClapTrap(const std::string _name);
        ClapTrap(const ClapTrap& copy);
        ~ClapTrap(void);
        ClapTrap& operator=(const ClapTrap& copy);
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        
        std::string getName(void) const;
        int getHit(void) const;
        int getEnergy(void) const;
        int getAttack(void) const;
};

#endif