/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 10:49:11 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/05 11:08:08 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T& a, T& b){
    T c = a;
    a = b;
    b = c;
};

template<typename T>
const T& min(const T& a, const T& b){
   return (a < b ? a : b); 
};

template<typename T>
const T& max(const T& a, const T& b){
    return (a > b ? a : b);
};

#endif