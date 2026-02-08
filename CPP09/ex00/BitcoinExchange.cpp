/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:56:21 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/06 19:22:11 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::_btcDatabase;

BitcoinExchange::~BitcoinExchange(void){};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other){
    (void)other;
    return *this;
};

void BitcoinExchange::loadDatabaseFile(void){
    std::ifstream dataFile("data.csv");
    if(!dataFile.is_open())
        throw std::runtime_error("Data file open error");
    
    std::string line;
    std::string dateStr;
    std::string valueStr;
    while(std::getline(dataFile, line)){
        std::stringstream ss(line);
        std::getline(ss, dateStr, ',');
        std::getline(ss, valueStr, '\n');
        
        float value = std::atof(valueStr.c_str());
        _btcDatabase[dateStr] = value;
    }
    // std::map<std::string, float>::iterator it = _btcDatabase.begin();
    // std::cout << "Date: " << it->first << " price: " << it->second << std::endl;
    // it++;
    // std::cout << "Date: " << it->first << " price: " << it->second << std::endl;
};

bool BitcoinExchange::validDate(const std::string& date){
    std::map<std::string, float>::iterator it = _btcDatabase.lower_bound(date);
    
    if(it == _btcDatabase.end() || date.length() != 10 || date[4] != '-' || date[7] != '-')
        return std::cout << "Error: bad input => " << date << std::endl, false;

    for (size_t i = 0; i < date.length(); i++){
        if(i == 4 || i == 7) continue;
        if (!isdigit(date[i]))
            return std::cout << "Error: bad input => " << date << std::endl, false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if(year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1 || day > 31)
        return std::cout << "Error: bad input => " << date << std::endl, false;
    
    return true;
}

bool BitcoinExchange::validValue(const std::string& value){
    float num = std::atof(value.c_str());
    if (std::isinf(num) || (num == 0.0 && value != "0.0"))
        return std::cout << "Error: bad value input => " << value << std::endl, false;

    if (num < 0)
        return std::cout << "Error: negative value => " << value << std::endl, false;
    
    if (num > 2.147483647e+09) {
        return std::cout << "Error: value too big => " << value << std::endl, false;
    }
    return true;
}

float BitcoinExchange::findPrice(const std::string& date){
    std::map<std::string, float>::iterator it = _btcDatabase.lower_bound(date);
    
    if(it == _btcDatabase.begin() || it->first == date)
        return it->second;
    it--;
    return it->second;
}

void BitcoinExchange::bitcoinExchange(const std::string& inputFileName){
    std::ifstream inputFile(inputFileName.c_str());
    if(!inputFile.is_open())
        throw std::runtime_error("Input file open error");
    
    std::string line;
    std::string dateStr;
    std::string valueStr;
    while(std::getline(inputFile, line)){
        std::stringstream ss(line);
        std::getline(ss, dateStr, ' ');
        std::getline(ss, valueStr, ' ');
        std::getline(ss, valueStr, '\n');
        
        if(validDate(dateStr) && validValue(valueStr)){
            float inputVal = std::atof(valueStr.c_str());
            float databaseVal = findPrice(dateStr);
            std::cout << dateStr << " => " << inputVal << " = " << inputVal * databaseVal << std::endl;
        }
    }
};