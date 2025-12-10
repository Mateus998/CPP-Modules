/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:21:13 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/10 13:10:36 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>
#include <float.h>
#include <climits>

class Fixed{
    public:
        Fixed(void);
        Fixed(const Fixed& f);
        Fixed(const int n);
        Fixed(const float n);
        ~Fixed(void);

        Fixed& operator=(const Fixed& f);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;
    private:
        int _raw;
        static const int _bit;
};
std::ostream& operator<<(std::ostream& os, const Fixed& n);

#endif