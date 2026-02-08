/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:10:37 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/07 18:56:25 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <cstdlib>

extern std::stack<double> stack;

enum SIGN{
    SUM = 0,
    SUB = 1,
    MULT = 2,
    DIV = 3,
    ERR = 4
};

void validateValue(const std::string& value);
SIGN signValue(const std::string& value);
void makeResult(SIGN sign);

#endif