/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/04/01 22:48:59 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void plusOne(int& i){
    i++;
}

void printElem(const int& i){
    std::cout << i << std::endl;
}

void addA(std::string& s){
    s.append("a");
}

void printStr(const std::string& s){
    std::cout << s << std::endl;
}

int main(void) {
    int array[4] = {1, 2, 3, 4};
    std::string strs[2] = {"Ol", "Arar"};
    
    iter<int>(array, 4, plusOne);
    iter<int>(array, 4, printElem);

    iter<std::string>(strs, 2, addA);
    iter<std::string>(strs, 2, printStr);
}
