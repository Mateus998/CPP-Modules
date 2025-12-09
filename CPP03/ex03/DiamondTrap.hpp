/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:18 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:49:03 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap{
    private:
        std::string _name;
    public:
        DiamondTrap(void);
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& copy);
        ~DiamondTrap(void);
        DiamondTrap& operator=(const DiamondTrap& copy);
        void attack(const std::string& target);
        std::string getName(void) const;
        void whoAmI(void);
};

#endif