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

#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();
    Animal* a3 = new Animal();
    a1->makeSound();
    a2->makeSound();
    a3->makeSound();
    delete a1;
    delete a2;
    delete a3;
return 0;
}
