/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:14:29 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 14:45:07 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreationForm", 145, 137), _target(target){};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form)
: AForm("ShrubberyCreationForm", 145, 137), _target(form.getTarget()){
    *this = form;
};

ShrubberyCreationForm::~ShrubberyCreationForm(void){};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form){
    this->AForm::operator=(form);
    return *this;
};

const std::string& ShrubberyCreationForm::getTarget(void) const{
    return _target;
};

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{

    this->checkExecutability(executor);
    std::string name;
    std::ofstream file;

    name = _target + "_shrubbery";
    file.open(name.c_str(), std::ofstream::out);

    file << "               ,@@@@@@@,                 " << std::endl;
    file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.     " << std::endl;
    file << "    ,&\\%\\%&%&&%,@@@@@/@@@@@@,8888\\88/8o    " << std::endl;
    file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'   " << std::endl;
    file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'   " << std::endl;
    file << "   %&&%/ %&\\%\\%&&@@\\ V /@@' `88\\8 `/88'    " << std::endl;
    file << "   `&%\\ ` /%&'    |.|        \\ '|8'      " << std::endl;
    file << "       |o|        | |         | |        " << std::endl;
    file << "       |.|        | |         | |        " << std::endl;
    file << "   _\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
    file.close();
};