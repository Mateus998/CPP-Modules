/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:23:28 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/02 17:54:41 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
    const std::string _name;
    const int _signGrade;
    const int _execGrade;
    bool _signed;
    Form(void);

    class GradeTooLowException : public std::exception{
        public:
        const char *what() const throw(){
            return "Grade too low for this form";
        }
    };

    public:
    Form(const std::string& name, int signGrade, int execGrade);
    Form(const Form &f);
    ~Form(void);

    Form& operator=(const Form& f);
    const std::string& getName(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;
    bool getSigned(void) const;
    void beSigned(const Bureaucrat& b);
};
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif