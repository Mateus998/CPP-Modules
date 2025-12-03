/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/03 17:59:47 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
Point a(5.5, 3.2);
Point b(7, 9);
Point c(1.2, 6.2);
Point p(5.5, 6);
if (bsp(a,b,c,p))
    std::cout << "is inside\n";
else
    std::cout << "is not inside\n";
return 0;
}
