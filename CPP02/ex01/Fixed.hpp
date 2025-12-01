/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:21:13 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/01 16:03:25 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
    public:
        Fixed(void);
        Fixed(const Fixed& f);
        ~Fixed(void);

        Fixed& operator=(const Fixed& f);

        int getRawBits(void) const;
        void setRawBits(int const raw);
    private:
        int _i;
        static const int _bit;
};

#endif