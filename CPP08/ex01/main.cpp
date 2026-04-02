/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/04/02 16:22:27 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>

int main(void) {
    try{
        
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
        
        srand(time(0));
        std::vector<int> vec(15000);
        for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++){
            *it = rand() % 15000;
        }
        
        Span sp2(15000);
        sp2.addNumbers(vec.begin(), vec.end());
        std::cout << sp2.shortestSpan() << std::endl;
        std::cout << sp2.longestSpan() << std::endl;
        sp.addNumbers(vec.begin(), vec.end());
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        
        Span sp(5);
        sp.addNumber(6);
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        Span sp(5);
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
