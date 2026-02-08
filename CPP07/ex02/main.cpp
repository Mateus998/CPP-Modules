/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/05 13:58:54 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void) {
    Array<int> a(5);
    a[1] = 5;
    for(size_t i = 0; i < a.size(); i++){
        std::cout << a[i] << std::endl;
    }
    try{
        a[7] = 6;
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
