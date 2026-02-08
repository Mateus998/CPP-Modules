/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:38:12 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/04 17:38:52 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cstdlib>

class ScalarConverter{
    private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter& other);
    ~ScalarConverter(void);
    ScalarConverter& operator=(const ScalarConverter& other);
    
    public:
    class InvalidValueToConvert : public std::exception{
        private:
        const char* _msg;
        public:
        InvalidValueToConvert(void);
        InvalidValueToConvert(const char* msg);
        const char* what() const throw();
    };
    
    static void convert(const char* value);
};

#endif