/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:33:23 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 18:50:24 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char* Intern::InvalidFormName::what() const throw(){
    return "Invalid form name";
};
Intern::Intern(void){};
Intern::Intern(const Intern& other){
    *this = other;
};
Intern::~Intern(void){};

Intern& Intern::operator=(const Intern& other){
    (void)other;
    return *this;
};

Intern::FORM Intern::formType(const std::string& type){
    if (type == "presidential pardon") return PRESIDENTIAL;
    if (type == "robotomy request") return ROBOTOMY;
    if (type == "shrubbery creation") return SHRUBBERY;
    return UNKNOWN;
};

AForm* Intern::makeForm(const std::string& formName, const std::string& formTarget){
    FORM type = formType(formName);
    AForm* form;
    
    switch (type)
    {
    case PRESIDENTIAL:
        form = new PresidentialPardonForm(formTarget);
        break;
    case ROBOTOMY:
        form = new RobotomyRequestForm(formTarget);
        break;
    case SHRUBBERY:
        form = new ShrubberyCreationForm(formTarget);
        break;
    default:
        throw InvalidFormName();
    }
    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
};