/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:59:28 by mateferr          #+#    #+#             */
/*   Updated: 2026/03/31 17:20:29 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false){
    if(this->_execGrade < 1 || this->_signGrade < 1)
        throw GradeTooHighException();
    if(this->_execGrade > 150 || this->_signGrade > 150)
        throw GradeTooLowException();
};

Form::Form(const Form& f): _name(f.getName()), _signGrade(f.getSignGrade()), _execGrade(f.getExecGrade()){
    *this = f;
};

Form::~Form(void){};

Form& Form::operator=(const Form& f){
    if (this != &f){
        _signed = f.getSigned();
    }
    return *this;
};
const std::string& Form::getName(void) const{
    return _name;
};
int Form::getSignGrade(void) const{
    return _signGrade;
};
int Form::getExecGrade(void) const{
    return _execGrade;
};
bool Form::getSigned(void) const{
    return _signed;
};
void Form::beSigned(const Bureaucrat& b){
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
};

std::ostream& operator<<(std::ostream& os, const Form& f){
    os << "Form name: " << f.getName() << "sign grade: " << f.getSignGrade() << "exec grade: "
     << f.getExecGrade() << "is signed: " << (f.getSigned() ? "true" : "false");
    return os;
}