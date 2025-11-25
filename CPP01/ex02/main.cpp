/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:58:24 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/25 15:09:57 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    
    std::cout
    << "Memory adress of the string: " << &str << '\n'
    << "Memory adress held by stringPTR: " << stringPTR << '\n'
    << "Memory adress held by stringREF: " << &stringREF << '\n'
    << '\n' << "Value of the string: " << str << '\n'
    << "Value pointed to by stringPTR: " << *stringPTR << '\n'
    << "Value pointed to by stringREF: " << stringREF << '\n';
}