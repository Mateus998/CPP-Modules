/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:08:00 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 15:12:15 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardonForm", 25, 5), _target(target){};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form)
: AForm("PresidentialPardonForm", 25, 5), _target(form.getTarget()){
    *this = form;
};

PresidentialPardonForm::~PresidentialPardonForm(void){};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& form){
    this->AForm::operator=(form);
    return *this;
};

const std::string& PresidentialPardonForm::getTarget(void) const{
    return _target;
};

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{

    this->checkExecutability(executor);
    
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
};