/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:33:36 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 18:20:34 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    private:
    enum FORM{
      PRESIDENTIAL = 0,
      ROBOTOMY = 1,
      SHRUBBERY = 2,
      UNKNOWN = 3  
    };
    FORM formType(const std::string& type);
    class InvalidFormName : public std::exception{
        public:
        const char* what() const throw();
    };

    public:
    Intern(void);
    Intern(const Intern& other);
    ~Intern(void);

    Intern& operator=(const Intern& other);
    AForm* makeForm(const std::string& formName, const std::string& formTarget);
};

#endif