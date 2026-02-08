/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:05:16 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 14:57:38 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
#include <cstdlib>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    Bureaucrat(void);

    class GradeTooHighException : public std::exception{
        public:
        const char *what() const throw(){
            return "Grade too high";
        }
    };
    class GradeTooLowException : public std::exception{
        public:
        const char *what() const throw(){
            return "Grade too low";
        }
    };

public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& b);
    ~Bureaucrat(void);

    Bureaucrat& operator=(const Bureaucrat& b);
    const std::string& getName(void) const;
    int getGrade(void) const;
    void increaseGrade(void);
    void decreaseGrade(void);
    void signForm(AForm& f);
    void executeForm(AForm const & form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
