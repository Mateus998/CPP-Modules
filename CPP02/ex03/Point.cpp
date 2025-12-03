/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:17:26 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/03 14:56:35 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void):x(0),y(0){}

Point::Point(const float x, const float y):x(x), y(y){}

Point::Point(const Point& point):x(point.x), y(point.y){}

Point::~Point(void){}

Point& Point::operator=(const Point& point){
    (void)point;
    return *this;
}

float Point::getXvalue(void) const{
    return this->x.toFloat();
}

float Point::getYvalue(void) const{
    return this->y.toFloat();
}