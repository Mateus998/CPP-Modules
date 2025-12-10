/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/10 17:37:18 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main( void ) {
    FragTrap a;
    FragTrap b("bObj");
    FragTrap c("cObj");
    c.attack(b.getName());
    b.takeDamage(c.getAttack());
    b.beRepaired(5);
    a = c;
    a.attack(c.getName());
    a.highFivesGuys();
    b.highFivesGuys();
    c.highFivesGuys();
return 0;
}
