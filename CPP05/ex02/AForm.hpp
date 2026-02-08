/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:23:28 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 11:47:29 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
    const std::string _name;
    const int _signGrade;
    const int _execGrade;
    bool _signed;
    AForm(void);

    public:
    AForm(const std::string& name, int signGrade, int execGrade);
    AForm(const AForm &f);
    virtual ~AForm(void);

    AForm& operator=(const AForm& f);
    const std::string& getName(void) const;
    int getSignGrade(void) const;
    int getExecGrade(void) const;
    bool getSigned(void) const;
    void beSigned(const Bureaucrat& b);
    void checkExecutability(Bureaucrat const & executor) const;
    virtual void execute(Bureaucrat const & executor) const = 0;

    class GradeTooLowException : public std::exception{
        private:
        const char *_msg;
        public:
        GradeTooLowException(void);
        GradeTooLowException(const char *msg);
        const char *what() const throw();
    };
    class GradeTooHighException : public std::exception{
        private:
        const char *_msg;
        public:
        GradeTooHighException(void);
        GradeTooHighException(const char *msg);
        const char *what() const throw();
    };
    class InvalidFormException : public std::exception{
        private:
        const char *_msg;
        public:
        InvalidFormException(void);
        InvalidFormException(const char *msg);
        const char *what() const throw();
    };
};
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif