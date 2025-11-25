/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:16:31 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/25 13:26:00 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(){
    int N = 20;
    Zombie* zHorde = Zombie::zombieHorde(N, "Zs");
    if (!zHorde)
        return 1;
    for(int i = 0; i < N; i++)
        zHorde[i].announce();
    delete[] zHorde;
    return 0;
}