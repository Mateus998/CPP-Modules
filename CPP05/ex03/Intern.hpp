/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:33:36 by mateferr          #+#    #+#             */
/*   Updated: 2026/03/31 19:15:38 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    private:
    AForm* newRobotomy(const std::string& target);
    AForm* newPresidential(const std::string& target);
    AForm* newShrubbery(const std::string& target);

    public:
    Intern(void);
    Intern(const Intern& other);
    ~Intern(void);

    Intern& operator=(const Intern& other);
    AForm* makeForm(const std::string& formName, const std::string& formTarget);
};

#endif