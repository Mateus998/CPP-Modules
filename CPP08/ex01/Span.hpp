/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:39:37 by mateferr          #+#    #+#             */
/*   Updated: 2026/04/02 16:41:44 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <numeric>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <iterator>
#include <cstddef>

class Span{
    private:
    std::vector<int> _storage;
    unsigned int _capacity;
    Span(void);

    public:
    Span(unsigned int N);
    Span(const Span& other);
    ~Span(void);

    Span& operator=(const Span& other);
    void addNumber(int value);
    int shortestSpan(void) const;
    int longestSpan(void) const;

    template<typename I>
    void addNumbers(I begin, I end){
        std::ptrdiff_t range = std::distance(begin, end);
        if(range < 0)
            throw std::logic_error("Invalid range");
            
        if(_storage.size() + static_cast<size_t>(range) > _capacity)
            throw std::logic_error("Not enough space left");
        
        _storage.insert(_storage.end(), begin, end);
    };
};

#endif