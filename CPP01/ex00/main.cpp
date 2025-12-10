/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:16:31 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/10 10:58:30 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    Zombie* z1 = Zombie::newZombie("Heapper");
    z1->announce();
    Zombie::randomChump("Stacker");
    if (z1) delete z1;
    return 0;
}