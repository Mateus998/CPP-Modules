/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/04/02 15:05:22 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>

int main(void) {
    
    std::vector<int> vec;
    std::deque<int> deq;
    std::list<int> lst;
    std::set<int> set;
    
    vec.push_back(1);
    deq.push_back(1);
    lst.push_back(1);
    set.insert(1);

    try{
        easyfind(vec, 1);
        easyfind(deq, 1);
        easyfind(lst, 1);
        easyfind(set, 1);
        std::cout << "DONE!" << std::endl;
        easyfind(vec, 5);
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        easyfind(deq, 5);
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        easyfind(lst, 5);
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    try{
        easyfind(set, 5);
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
