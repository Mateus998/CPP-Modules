/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:35:34 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/02 15:17:03 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bit = 8;

Fixed::Fixed(void):_raw(0){
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& f){
    std::cout << "Copy constructor called\n";
    this->operator=(f);
}

Fixed::~Fixed(void){
    std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& f){
    std::cout << "Copy assigment operator called\n";
    if (this != &f)
        this->_raw = f.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called\n";
    return this->_raw;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called\n";
    this->_raw = raw;
}

