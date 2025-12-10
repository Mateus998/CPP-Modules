/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/10 19:22:47 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) {
Point a(0, 0);
Point b(4, 0);
Point c(2, 4);
Point pIn(2.2f, 2);
Point pOut(4, 4.56f);
Point pEdge(3, 0);
if (bsp(a,b,c,pIn))
    std::cout << "pIn is inside\n";
else
    std::cout << "pIn is not inside\n";
if (bsp(a,b,c,pOut))
    std::cout << "pOut is inside\n";
else
    std::cout << "pOut is not inside\n";
if (bsp(a,b,c,pEdge))
    std::cout << "pEdge is inside\n";
else
    std::cout << "pEdge is not inside\n";
return 0;
}
