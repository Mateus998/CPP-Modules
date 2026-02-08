/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:50:39 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/07 18:57:25 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<double> stack;

void validateValue(const std::string& value){
    if(value.length() != 1)
        throw std::runtime_error("Error: Invalid value");
    if (!isdigit(value[0]) && value != "+" && value != "-" && value != "/" && value != "*")
        throw std::runtime_error("Error: No digit nether sign");
}

SIGN signValue(const std::string& value){
    if(value == "+") return SUM;
    if(value == "-") return SUB;
    if(value == "*") return MULT;
    if(value == "/") return DIV;
    return ERR;
}

void makeResult(SIGN sign){
    if(stack.size() < 2)
        throw std::runtime_error("Error: Missing digit before sign");
        
    double second = stack.top();
    stack.pop();
    double first = stack.top();
    stack.pop();
    double result;
    
    switch(sign){
        case 0:
            result = first + second;
            break;
        case 1:
            result = first - second;
            break;
        case 2:
            result = first * second;
            break;
        case 3:
            if (second == 0)
                throw std::logic_error("Error: Division by zero");
            result = first / second;
            break;
        default:
            break;
    }
    stack.push(result);
}