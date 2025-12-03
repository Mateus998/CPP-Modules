/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:57:07 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/03 17:59:36 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* Formulas 
lei dos cossenos
a²=b²+c²-2*b*c*cos(Â)
cos(Â)=(b²+c²-a²)/(2*b*c)

distancia
d=sqrt((x2-x1)² + (y2-y1)²)

area
a*b*sen(a^b)/2
*/

static double angleCalc(double a, double b, double c){
    double angle = (b*b + c*c - a*a) / (2*b*c);
    return acos(angle) * 180/M_PI;
}

static double edgeCalc(Point const a, Point const b){
    double xSqr = std::pow(b.getXvalue() - a.getXvalue(), 2);
    double ySqr = std::pow(b.getYvalue() - a.getYvalue(), 2);
    return std::sqrt(xSqr + ySqr);
}

static double triangleCalc(Point const l, Point const p, Point const r){
    double lp = edgeCalc(l,p);
    double pr = edgeCalc(p,r);
    double lr = edgeCalc(l,r);
    std::cout << "\nlados\n";
    std::cout << lp << '\n';
    std::cout << pr << '\n';
    std::cout << lr << '\n';
    return angleCalc(lr, lp, pr);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
    double angleAPB = triangleCalc(a, point, b);
    double angleAPC = triangleCalc(a, point, c);
    double angleBPC = triangleCalc(b, point, c);
    std::cout << "\nangulos\n";
    std::cout << angleAPB << '\n';
    std::cout << angleAPC << '\n';
    std::cout << angleBPC << '\n';
    std::cout << angleAPB + angleAPC + angleBPC << '\n';
    if (angleAPB + angleAPC + angleBPC == 360)
        return true;
    return false;
}