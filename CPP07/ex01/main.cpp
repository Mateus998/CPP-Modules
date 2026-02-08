/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/05 11:56:00 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<typename T>
void plusOne(T& i){
    i++;
}

template<typename T>
void printElem(const T& i){
    std::cout << i << std::endl;
}

int main(void) {
    int array[] = {1, 2, 3, 4};
    iter<int>(array, 4, plusOne<int>);
    iter<int>(array, 4, printElem<int>);
}
