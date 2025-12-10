/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/10 13:36:34 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << std::endl;

Fixed c(5.5f);
Fixed d(2);
std::cout << (c < d) << std::endl;
std::cout << (c > d) << std::endl;
std::cout << (c <= d) << std::endl;
std::cout << (c >= d) << std::endl;
std::cout << (c == d) << std::endl;
std::cout << (c != d) << std::endl;
std::cout << std::endl;

std::cout << (c + d) << std::endl;
std::cout << (c - d) << std::endl;
std::cout << (c * d) << std::endl;
std::cout << (c / d) << std::endl;
std::cout << std::endl;

std::cout << (c) << std::endl;
std::cout << (++c) << std::endl;
std::cout << (d++) << std::endl;
std::cout << (d) << std::endl;
std::cout << (c) << std::endl;
std::cout << (--c) << std::endl;
std::cout << (d--) << std::endl;
std::cout << (d) << std::endl;
std::cout << std::endl;

std::cout << Fixed::max(c, d) << std::endl;
std::cout << Fixed::min(c, d) << std::endl;
return 0;
}
