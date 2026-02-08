/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:59:28 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 11:53:14 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException(void){
    _msg = "Grade too high";
}
AForm::GradeTooHighException::GradeTooHighException(const char *msg): _msg(msg){};

const char *AForm::GradeTooHighException::what() const throw(){
    return _msg;
};

AForm::GradeTooLowException::GradeTooLowException(void){
    _msg = "Grade too Low";
}
AForm::GradeTooLowException::GradeTooLowException(const char *msg): _msg(msg){};

const char *AForm::GradeTooLowException::what() const throw(){
    return _msg;
};

AForm::InvalidFormException::InvalidFormException(void){
    _msg = "Form can't be executed";
}
AForm::InvalidFormException::InvalidFormException(const char *msg): _msg(msg){};

const char *AForm::InvalidFormException::what() const throw(){
    return _msg;
};

AForm::AForm(const std::string& name, int signGrade, int execGrade): _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false){};

AForm::AForm(const AForm& f): _name(f.getName()), _signGrade(f.getSignGrade()), _execGrade(f.getExecGrade()){
    *this = f;
};
AForm::~AForm(void){};

AForm& AForm::operator=(const AForm& f){
    if (this != &f){
        _signed = f.getSigned();
    }
    return *this;
};
const std::string& AForm::getName(void) const{
    return _name;
};
int AForm::getSignGrade(void) const{
    return _signGrade;
};
int AForm::getExecGrade(void) const{
    return _execGrade;
};
bool AForm::getSigned(void) const{
    return _signed;
};
void AForm::beSigned(const Bureaucrat& b){
    if (b.getGrade() > _signGrade)
        throw GradeTooLowException("Grade too low to sign the form");
    _signed = true;
};

void AForm::checkExecutability(Bureaucrat const & executor) const{
    if(!this->getSigned())
        throw InvalidFormException("Form not signed");
    if(executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException("Grade too low to execute the form");
};

std::ostream& operator<<(std::ostream& os, const AForm& f){
    os << "Form name: " << f.getName() << "sign grade: " << f.getSignGrade() << "exec grade: "
     << f.getExecGrade() << "is signed: " << (f.getSigned() ? "true" : "false");
    return os;
}