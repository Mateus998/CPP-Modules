/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:35:34 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/02 16:26:28 by mateferr         ###   ########.fr       */
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

Fixed::Fixed(const int n){
    std::cout << "Int constructor called\n";
    _raw = n * (1 << _bit);
}

Fixed::Fixed(const float n){
    std::cout << "Float constructor called\n";
    _raw = roundf(n * (1 << _bit));
}

Fixed::~Fixed(void){
    std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& f){
    std::cout << "Copy assignment operator called\n";
    if (this != &f)
        this->_raw = f.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& n){
    os << n.toFloat();
    return os;
}

int Fixed::getRawBits(void) const{
    // std::cout << "getRawBits member function called\n";
    return this->_raw;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called\n";
    this->_raw = raw;
}

float Fixed::toFloat(void) const{
    return static_cast<float>(_raw) / (1 << _bit);
}

int Fixed::toInt(void) const{
    return _raw / (1 << _bit);
}
