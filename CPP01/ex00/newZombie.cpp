/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:16:40 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/25 13:22:49 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::newZombie( std::string name ){
    Zombie* zombie = new(std::nothrow) Zombie(name);
    if (!zombie)
        return NULL;
    return zombie;
}