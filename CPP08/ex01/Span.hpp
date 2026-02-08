/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:39:37 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/05 20:06:37 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <numeric>
#include <vector>
#include <stdexcept>
#include <iostream>

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
        for (; begin != end; begin++){
            this->addNumber(*begin);
        }
    };
};

#endif