/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:52:09 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 15:02:04 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequestForm", 72, 45), _target(target){};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form)
: AForm("RobotomyRequestForm", 72, 45), _target(form.getTarget()){
    *this = form;
};

RobotomyRequestForm::~RobotomyRequestForm(void){};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form){
    this->AForm::operator=(form);
    return *this;
};

const std::string& RobotomyRequestForm::getTarget(void) const{
    return _target;
};

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{

    this->checkExecutability(executor);
    
    srand(time(0));
    std::cout << "* Unbearable drilling noises *" << std::endl;
	if (rand() % 2 == 0)
	{
		std::cout << this->getTarget();
		std::cout << " has been successfully robotomized!" << std::endl;
	}
	else
		std::cout << "The robotomization on " << this->getTarget() << " failed!" << std::endl;
};