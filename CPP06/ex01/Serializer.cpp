/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 22:56:10 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/04 22:59:21 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void){};

Serializer::Serializer(const Serializer& other){
    *this = other;
};

Serializer::~Serializer(void){};

Serializer& Serializer::operator=(const Serializer& other){
    (void)other;
    return *this;
};


uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
};

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
};
