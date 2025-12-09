/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:23:49 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:19:39 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){
    _levels[0] = &Harl::debug;
    _levels[1] = &Harl::info;
    _levels[2] = &Harl::warning;
    _levels[3] = &Harl::error;
    _inputs[0] = "DEBUG";
    _inputs[1] = "INFO";
    _inputs[2] = "WARNING";
    _inputs[3] = "ERROR";
}

Harl::~Harl(void){}

void Harl::complain(std::string level){
    for (int i = 0; i < 4; i++){
        if(level == _inputs[i]){
           return (this->*_levels[i])();
        }
    }
    std::cerr << "Invalid level: " << level << "\n";
}

void Harl::debug(void){
    std::cout << "DEBUG msg: I love having extra bacon for my" <<
    " 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info(void){
    std::cout << "INFO msg: I cannot believe adding extra bacon costs more money." <<
    " You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning(void){
    std::cout << "WARNING msg: I think I deserve to have some extra bacon for free." <<
    " I’ve been coming for years, whereas you started working here just last month.\n";
}

void Harl::error(void){
    std::cout << "ERROR msg: This is unacceptable! I want to speak to the manager now.\n";
}