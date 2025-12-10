/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/10 18:09:19 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main( void ) {
    int arraySize = 6;
    Animal* animals[arraySize];
    for (int i = 0; i < arraySize / 2; i++){
        animals[i] = new Dog();
    }
    for (int i = arraySize / 2; i < arraySize; i++){
        animals[i] = new Cat();
    }
    for (int i = 0; i < arraySize; i++){
        delete animals[i];
    }
    Dog d1;
    Dog d2(d1);
    d1.getBrain()->setIdea("hello d1");
    d2.getBrain()->setIdea("hello d2");
    std::cout << d1.getBrain()->ideas[0] << " " << d2.getBrain()->ideas[0] << std::endl;
return 0;
}
