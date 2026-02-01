/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/12 13:46:11 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void ) {
    Bureaucrat b("Edward", 1);
    std::cout << b << std::endl;

    Bureaucrat r("Richard", 150);
    std::cout << r << std::endl;

    try{
        b.increaseGrade();
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }

    
    try{
        r.decreaseGrade();
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
return 0;
}
