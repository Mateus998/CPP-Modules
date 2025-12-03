/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:07:59 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/03 14:58:55 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
    private:
        const Fixed x;
        const Fixed y;
        
    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point& point);
        ~Point(void);
        
        Point& operator=(const Point& point);
        float getXvalue(void) const;
        float getYvalue(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif