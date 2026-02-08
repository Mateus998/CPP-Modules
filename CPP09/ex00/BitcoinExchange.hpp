/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:38:11 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/06 19:14:38 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>

class BitcoinExchange{
    
    private:
    static std::map<std::string, float> _btcDatabase;
    
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange& other);
    ~BitcoinExchange(void);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    static float findPrice(const std::string& date);
    static bool validValue(const std::string& value);
    static bool validDate(const std::string& date);

    public:
    static void loadDatabaseFile(void);
    static void bitcoinExchange(const std::string& inputFileName);
};

#endif