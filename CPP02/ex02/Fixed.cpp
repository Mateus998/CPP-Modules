/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:35:34 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/02 19:23:01 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_bit = 8;

Fixed::Fixed(void):_raw(0){
    // std::cout << "Default constructor called\n";
}
Fixed::Fixed(const Fixed& f){
    // std::cout << "Copy constructor called\n";
    *this = f;
}
Fixed::Fixed(const int n){
    // std::cout << "Int constructor called\n";
    _raw = n * (1 << _bit);
}
Fixed::Fixed(const float n){
    // std::cout << "Float constructor called\n";
    _raw = roundf(n * (1 << _bit));
}
Fixed::~Fixed(void){
    // std::cout << "Destructor called\n";
}

Fixed& Fixed::operator=(const Fixed& f){
    // std::cout << "Copy assignment operator called\n";
    if (this != &f)
        this->_raw = f.getRawBits();
    return *this;
}
bool Fixed::operator>(const Fixed& f) const{
    if (this->_raw > f.getRawBits())
        return true;
    return false;
}
bool Fixed::operator<(const Fixed& f) const{
    if (this->_raw < f.getRawBits())
        return true;
    return false;
}
bool Fixed::operator>=(const Fixed& f) const{
    if (this->_raw >= f.getRawBits())
        return true;
    return false;
}
bool Fixed::operator<=(const Fixed& f) const{
    if (this->_raw <= f.getRawBits())
        return true;
    return false;
}
bool Fixed::operator==(const Fixed& f) const{
    if (this->_raw == f.getRawBits())
        return true;
    return false;
}
bool Fixed::operator!=(const Fixed& f) const{
    if (this->_raw != f.getRawBits())
        return true;
    return false;
}
/* equations formula
fac = 1 << _bit
n = _raw / fac

n1 + n2 = n3:
_raw1/fac + _raw2/fac = _raw3/fac
(_raw1+_raw2)/fac*fac = _raw3
_raw1+_raw2 = _raw3

n1 * n2 = n3
_raw1/fac * _raw2/fac = _raw3/fac
(_raw1*_raw2)/fac^2*fac = _raw3
(_raw1*_raw2)/fac = _raw3

n1 / n2 = n3
_raw1/fac / _raw2/fac = _raw3/fac
_raw1/fac * fac/_raw2 = _raw3/fac
(_raw1/_raw2)*fac = _raw3
*/
Fixed Fixed::operator+(const Fixed& f) const{
    Fixed temp;
    temp.setRawBits(this->_raw + f.getRawBits());
    return temp;
}
Fixed Fixed::operator-(const Fixed& f) const{
    Fixed temp;
    temp.setRawBits(this->_raw - f.getRawBits());
    return temp;
}
Fixed Fixed::operator*(const Fixed& f) const{
    Fixed temp;
    temp.setRawBits(this->_raw * f.getRawBits() / (1 << _bit));
    return temp;
}
Fixed Fixed::operator/(const Fixed& f) const{
    Fixed temp;
    temp.setRawBits(this->_raw / f.getRawBits() * (1 << _bit));
    return temp;
}
std::ostream& operator<<(std::ostream& os, const Fixed& n){
    os << n.toFloat();
    return os;
}
Fixed& Fixed::operator++(void){
    _raw += 1;
    return *this;
}
Fixed Fixed::operator++(int){
    Fixed prev = *this;
    this->_raw += 1;
    return prev;
}
Fixed& Fixed::operator--(void){
    _raw -= 1;
    return *this;
}
Fixed Fixed::operator--(int){
    Fixed prev = *this;
    this->_raw -= 1;
    return prev;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2){
    if (f1.getRawBits() < f2.getRawBits())
        return f1;
    return f2;
}
const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2){
    if (f1.getRawBits() < f2.getRawBits())
        return f1;
    return f2;
}
Fixed& Fixed::max(Fixed& f1, Fixed& f2){
    if (f1.getRawBits() > f2.getRawBits())
        return f1;
    return f2;
}
const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2){
    if (f1.getRawBits() > f2.getRawBits())
        return f1;
    return f2;
}

int Fixed::getRawBits(void) const{
    // std::cout << "getRawBits member function called\n";
    return this->_raw;
}
void Fixed::setRawBits(int const raw){
    // std::cout << "setRawBits member function called\n";
    this->_raw = raw;
}
float Fixed::toFloat(void) const{
    return static_cast<float>(_raw) / (1 << _bit);
}
int Fixed::toInt(void) const{
    return _raw / (1 << _bit);
}
