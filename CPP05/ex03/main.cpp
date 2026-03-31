/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/03/31 18:59:30 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main( void ) {
    Intern i;
    Bureaucrat b1("B1", 1);
    
    AForm* f = i.makeForm("presidential pardon", "target");
    b1.signForm(*f);
    b1.executeForm(*f);
    delete f;
    f = i.makeForm("presidential pard3on", "target");
    delete f;
return 0;
}
