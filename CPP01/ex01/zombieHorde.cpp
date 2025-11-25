/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:16:40 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/25 13:22:40 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde( int N, std::string name ){
    Zombie* zombies = NULL;
    if (N <= 0)
        return zombies;
    try{
        zombies = new Zombie[N];
        for(int i = 0; i < N; i++)
            zombies[i].setName(name);
        return zombies;
    }
    catch(const std::exception& err){
        delete[] zombies;
        std::cerr << err.what() <<'\n';
        return NULL;
    }
}