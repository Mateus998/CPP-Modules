/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 18:50:11 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main( void ) {
    Intern i;
    
    try{
        AForm* f = i.makeForm("presidential pard3on", "olaias");
        delete f;
    }
    catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
return 0;
}
