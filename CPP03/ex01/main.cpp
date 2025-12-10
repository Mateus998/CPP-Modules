/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/10 17:37:42 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main( void ) {
    ScavTrap a;
    ScavTrap b("bObj");
    ScavTrap c("cObj");
    c.attack(b.getName());
    b.takeDamage(c.getAttack());
    b.beRepaired(5);
    a = c;
    a.attack(c.getName());
    a.guardGate();
    b.guardGate();
    c.guardGate();
return 0;
}
