/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:50:31 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/05 19:46:06 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N): _capacity(N){
    this->_storage.reserve(N);
};

Span::Span(const Span& other){
    *this = other;
};
Span::~Span(void){};

Span& Span::operator=(const Span& other){
    if(this != &other){
        this->_capacity = other._capacity;
        this->_storage = other._storage;
    }
    return *this;
};

void Span::addNumber(int value){
    if (this->_storage.size() == this->_capacity)
        throw std::overflow_error("Storage out of space");
    
    this->_storage.push_back(value);
};

int Span::shortestSpan(void) const{
    if (this->_storage.size() < 2)
        throw std::logic_error("Storage size not enough");
    
    std::vector<int> tmp = this->_storage;
    std::sort(tmp.begin(), tmp.end());
    
    std::vector<int> dif(this->_storage.size());
    std::adjacent_difference(tmp.begin(), tmp.end(), dif.begin());
    
    std::vector<int>::iterator it = std::min_element(dif.begin() + 1, dif.end());
    return (*it);
};

int Span::longestSpan(void) const{
    if (this->_storage.size() < 2)
        throw std::logic_error("Storage size not enough");
    
    std::vector<int> tmp = this->_storage;
    std::sort(tmp.begin(), tmp.end());
    return (tmp.back() - tmp.front());
};