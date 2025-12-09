/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:15 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:44:16 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void){
    std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain& d){
    std::cout << "Brain copy constructor called\n";
    *this = d;
}

Brain::~Brain(void){
    std::cout <<"Brain destructor called\n";
}

Brain& Brain::operator=(const Brain& d){
    if (this != &d){
        for(int i = 0; i < 100; i++){
            ideas[i] = d.ideas[i];
        }
    }
    return *this;
}