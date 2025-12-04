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

#include "ClapTrap.hpp"

int main( void ) {
    ClapTrap a;
    ClapTrap b("test_name");
    ClapTrap c("cClapTrap");
    c.attack("test_name");
    b.takeDamage(5);
    b.beRepaired(5);
    a = c;
    a.attack("cClapTrap");
return 0;
}
