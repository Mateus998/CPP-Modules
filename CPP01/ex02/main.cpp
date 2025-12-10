/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:58:24 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:53:25 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    std::string str2 = "test str";
    
    std::cout
    << "Memory adress of the string: " << &str << '\n'
    << "Memory adress held by stringPTR: " << stringPTR << '\n'
    << "Memory adress held by stringREF: " << &stringREF << '\n'
    << "\nValue of the string: " << str << '\n'
    << "Value pointed to by stringPTR: " << *stringPTR << '\n'
    << "Value pointed to by stringREF: " << stringREF << '\n';
    
    stringREF = str2;
    stringPTR = &str2;
    std::cout
    << "\nMemory adress held by stringPTR: " << stringPTR << '\n'
    << "Value pointed to by stringPTR: " << *stringPTR << '\n'
    << "Memory adress held by stringREF: " << &stringREF << '\n'
    << "Value pointed to by stringREF: " << stringREF << '\n'
    << "Value of the string: " << str << '\n';
}