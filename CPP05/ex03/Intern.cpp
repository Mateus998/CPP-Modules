/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:33:23 by mateferr          #+#    #+#             */
/*   Updated: 2026/03/31 19:39:34 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void){};
Intern::Intern(const Intern& other){
    *this = other;
};
Intern::~Intern(void){};

Intern& Intern::operator=(const Intern& other){
    (void)other;
    return *this;
};

AForm* Intern::newRobotomy(const std::string& target){
    return new RobotomyRequestForm(target);
}
AForm* Intern::newPresidential(const std::string& target){
    return new PresidentialPardonForm(target);
}
AForm* Intern::newShrubbery(const std::string& target){
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget){
    std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (Intern::*forms[3])(const std::string& target) = {&Intern::newShrubbery, &Intern::newRobotomy, &Intern::newPresidential};
    
    for(int i = 0; i < 3; i++){
        if(formName == names[i]){
            std::cout << "Intern creates " << names[i] << std::endl;
            return (this->*forms[i])(formTarget);
        }
    }
    std::cout << "Invalid form name" << std::endl;
    return NULL;
};