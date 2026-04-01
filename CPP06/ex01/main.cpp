/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/04/01 18:20:23 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
    Data origPtr = Data();
    
    uintptr_t serNum = Serializer::serialize(&origPtr);

    Data* serPtr = Serializer::deserialize(serNum);

    std::cout << "original pointer: " << &origPtr << std::endl;
    std::cout << "serialized number: " << serNum << std::endl;
    std::cout << "deserialized pointer: " << serPtr << std::endl;
return 0;
}
