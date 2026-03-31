/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/03/31 17:27:55 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {
    Form f1("form1", 5, 10);
    Form f2("form2", 1, 1);
    Bureaucrat b1("Edward", 3);
    
    try{
        Form f1("form1", 0, 10);
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    try{
        Form f2("form2", 1, 151);
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    try{
        b1.signForm(f2);
    }catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    b1.signForm(f1);
return 0;
}
