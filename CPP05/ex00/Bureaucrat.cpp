#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name), grade(grade){
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
        grade = b.getGrade();
    return *this;
}

std::string Bureaucrat::getName(void) const{
    return name;
}
int Bureaucrat::getGrade(void) const{
    return grade;
}
void Bureaucrat::increaseGrade(void){
    if(grade <= 1)
        throw GradeTooHighException();
    grade--;
}
void Bureaucrat::decreaseGrade(void){
    if(grade >= 150)
        throw GradeTooLowException();
    grade++;
}
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}