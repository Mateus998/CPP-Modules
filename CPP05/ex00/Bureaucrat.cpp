/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:05:03 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/02 17:44:09 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){}

Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name), _grade(grade){
    if(this->getGrade() < 1)
        throw GradeTooHighException();
    if(this->getGrade() > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& b){
    *this = b;
}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& b){
    if (this != &b)
        _grade = b.getGrade();
    return *this;
}

const std::string& Bureaucrat::getName(void) const{
    return _name;
}
int Bureaucrat::getGrade(void) const{
    return _grade;
}
void Bureaucrat::increaseGrade(void){
    if(_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}
void Bureaucrat::decreaseGrade(void){
    if(_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}