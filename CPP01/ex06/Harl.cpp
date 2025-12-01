/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:23:49 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/01 12:49:42 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void){}

Harl::~Harl(void){}

Harl::Level Harl::argToLevel(const std::string arg){
    if (arg == "DEBUG") return DEBUG;
    if (arg == "INFO") return INFO;
    if (arg == "WARNING") return WARNING;
    if (arg == "ERROR") return ERROR;
    return UNKNOWN;
}

void Harl::complains(const std::string arg){
    Level lvl = Harl::argToLevel(arg);
    switch (lvl){
        case DEBUG:
            debug();
            info();
            warning();
            error();
            break;
        case INFO:
            info();
            warning();
            error();
            break;
        case WARNING:
            warning();
            error();
            break;
        case ERROR:
            error();
            break;
        default:
            std::cout << "Invalid level: " << arg << '\n';
            break;
    }
}

void Harl::debug(void){
    std::cout << "DEBUG msg: I love having extra bacon for my" <<
    "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
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