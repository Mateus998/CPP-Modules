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

#include "FragTrap.hpp"

int main( void ) {
    FragTrap a;
    FragTrap b("bObj");
    FragTrap c("cObj");
    c.attack("bObj");
    b.takeDamage(5);
    b.beRepaired(5);
    a = c;
    a.attack("cObj");
    a.highFivesGuys();
    b.highFivesGuys();
    c.highFivesGuys();
return 0;
}
