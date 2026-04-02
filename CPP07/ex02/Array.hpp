/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:59:52 by mateferr          #+#    #+#             */
/*   Updated: 2026/04/02 12:37:35 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array{
    private:
    T* _array;
    size_t _size;
    
    class InvalidIdx : public std::exception{
        public:
        const char* what() const throw();
    };
    
    public:
    Array(void);
    ~Array(void);
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    T& operator[](const size_t i) const;
    size_t size(void) const;
};

#endif