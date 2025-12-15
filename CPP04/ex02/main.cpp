/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/15 11:13:44 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
    int arraySize = 10;
    AAnimal* animals[arraySize];
    for (int i = 0; i < arraySize / 2; i++){
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; i++){
        animals[i] = new Cat();
    }
    for (int i = 0; i < arraySize; i++){
        delete animals[i];
    }
return 0;
}
