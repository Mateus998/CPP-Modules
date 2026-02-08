/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:30:23 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/05 00:08:59 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <exception>

Base * generate(void){
    srand(time(0));
    
    int num = (rand() % 3) + 1;

    switch(num){
        case 1:
            return new A();
        case 2:
            return new B();
        default:
            return new C();
    }
};

void identify(Base* p){
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "p is from class A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "p is from class B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "p is from class C" << std::endl;    
};

void identify(Base& p){
    try{
        (void)dynamic_cast<A&>(p);
        std::cout << "p is from class A" << std::endl;
        return;
    }
    catch (std::exception&){}
    try{
        (void)dynamic_cast<B&>(p);
        std::cout << "p is from class B" << std::endl;
        return;
    }
    catch (std::exception&){}
    try{
        (void)dynamic_cast<C&>(p);
        std::cout << "p is from class C" << std::endl;
        return;
    }
    catch (std::exception&){}
};
