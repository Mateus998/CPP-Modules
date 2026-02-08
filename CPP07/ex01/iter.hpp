/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:29:33 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/05 11:44:41 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T* array, const size_t length, void (*func)(T&)){
    
    for(size_t i = 0; i < length; i++){
        func(array[i]);
    }
};

template<typename T>
void iter(T* array, const size_t length, void (*func)(const T&)){
    
    for(size_t i = 0; i < length; i++){
        func(array[i]);
    }
};

#endif