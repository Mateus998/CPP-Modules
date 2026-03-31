/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/03/31 18:28:13 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
    PresidentialPardonForm f11("target1");
    RobotomyRequestForm f12("target1");
    ShrubberyCreationForm f13("target1");
    
    PresidentialPardonForm f21("target2");
    RobotomyRequestForm f22("target2");
    ShrubberyCreationForm f23("target2");
    
    PresidentialPardonForm f31("target3");
    RobotomyRequestForm f32("target3");
    ShrubberyCreationForm f33("target3");
    
    Bureaucrat b1("B1", 1);
    Bureaucrat b2("B2", 40);
    Bureaucrat b3("B3", 100);
    
    b1.signForm(f13);
    b1.executeForm(f13);
    b1.signForm(f12);
    b1.executeForm(f12);
    b1.signForm(f11);
    b1.executeForm(f11);
    std::cout << std::endl;
    
    b2.signForm(f23);
    b2.executeForm(f23);
    b2.signForm(f22);
    b2.executeForm(f22);
    b2.signForm(f21);
    b2.executeForm(f21);
    std::cout << std::endl;
    
    b3.signForm(f33);
    b3.executeForm(f33);
    b3.signForm(f32);
    b3.executeForm(f32);
    b3.signForm(f31);
    b3.executeForm(f31);
    
return 0;
}
