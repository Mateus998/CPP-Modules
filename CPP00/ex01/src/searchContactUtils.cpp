/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchContactUtils.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:11:07 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/24 17:15:03 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/main.hpp"

std::string intToString(int i){
    std::ostringstream ostr;
    ostr << i;
    return ostr.str();
}

bool stringToInt(std::string str, int *i){
    if(!Contact::isdigitStr(str)){
        std::cout << "Invalid number input\n";
        return false;
    }
    std::istringstream istr(str);
    istr >> *i;
    return true;
}