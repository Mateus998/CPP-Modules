/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/04 14:19:01 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main( void ) {
    DiamondTrap b("bObj");
    DiamondTrap c("cObj");
    DiamondTrap a(c);
    DiamondTrap d;
    c.attack(b.getName());
    b.takeDamage(c.getAttack());
    b.beRepaired(5);
    a.attack(c.getName());
    a.whoAmI();
    b.whoAmI();
    c.whoAmI();
return 0;
}
