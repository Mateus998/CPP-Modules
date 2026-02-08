/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/07 18:54:00 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[]) {
    if(argc != 2)
        return std::cout << "Error" << std::endl, 1;
    try{
        std::string input(argv[1]);
        std::istringstream iss(input);
        std::string value;
        
        while (iss >> value){
            validateValue(value);
            if (isdigit(value[0]))
                stack.push(std::atoi(value.c_str()));
            else
                makeResult(signValue(value));
        }
        
        if(stack.size() != 1)
            throw std::runtime_error("Error: Missing final sign");
        std::cout << stack.top() << std::endl;
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
