/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:15:49 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/04 18:24:22 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){};

ScalarConverter::ScalarConverter(const ScalarConverter& other){
    *this = other;
};

ScalarConverter::~ScalarConverter(void){};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
    (void)other;
    return *this;
};

ScalarConverter::InvalidValueToConvert::InvalidValueToConvert(void){
    _msg = "Invalid value to convert";
};

ScalarConverter::InvalidValueToConvert::InvalidValueToConvert(const char* msg){
    _msg = msg;
};

const char* ScalarConverter::InvalidValueToConvert::what() const throw(){
    return _msg;
};

static bool isSpecialCase(const std::string& value){
    if (value == "-inf" || value == "+inf" || value == "nan")
        return true;
    if (value == "-inff" || value == "+inff" || value == "nanf")
        return true;
    return false;
}

static bool isInt(const std::string& value){
    size_t i = 0;
    
    if (value[i] == '+' || value[i] == '-')
        i = 1;
        
    for(; i < value.length(); i++){
        if (!isdigit(value[i]))
            return false;
    }
    return true;
}

static bool isFloat(const std::string& value){
    size_t fCount = 0;
    size_t dotCount = 0;
    size_t i = 0;
        
    if (value[value.length() - 1] != 'f')
        return false;
    
    if (value[i] == '+' || value[i] == '-')
        i = 1;
    
    for(; i < value.length(); i++){
        if (!isdigit(value[i])){
            if (value[i] == '.')
                dotCount++;
            else if (value[i] == 'f')
                fCount++;
            else
                return false;
            if (dotCount > 1 || fCount > 1)
                throw ScalarConverter::InvalidValueToConvert("Invalid number (float)");
        }
    }
    if (value.length() == dotCount + fCount)
        throw ScalarConverter::InvalidValueToConvert("Float with no digits");
    return true;
}

static bool isDouble(const std::string& value){
    size_t dotCount = 0;
    size_t i = 0;

    if (value[i] == '+' || value[i] == '-')
        i = 1;
        
    for(; i < value.length(); i++){
        if (!isdigit(value[i])){
            if (value[i] == '.')
                dotCount++;
            else
                return false;
            if (dotCount > 1)
                throw ScalarConverter::InvalidValueToConvert("Invalid number (double)");
        }
    }
    if (value.length() == dotCount)
        throw ScalarConverter::InvalidValueToConvert("Double with no digits");
    return true;
}

static bool isChar(const std::string& value){
    if (value.empty())
        throw ScalarConverter::InvalidValueToConvert("Empty value");
    if (value.length() == 3 && value[0] == '\'' && value[value.length() - 1] == '\'')
        return true;
    return false;
};

static void convertToTypesFromSpecial(const std::string& value){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (value == "-inf" || value == "+inf" || value == "nan"){
        std::cout << "float: " << value << "f" << std::endl;
        std::cout << "double: " << value << std::endl;
    }
    else{
        std::cout << "float: " << value << std::endl;
        std::cout << "double: ";
        for(size_t i = 0; i < value.length() - 1; i++)
            std::cout << value[i];
        std::cout << std::endl;
    }
};

static void convertToTypesFromChar(const char value){
    std::cout << "char: " << value << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
};

static void convertToTypesFromInt(const int value){
    if(value >= 32 && value <= 126)
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (value == std::numeric_limits<int>::infinity() || value == -std::numeric_limits<int>::infinity())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << value << std::endl;
    if (value == std::numeric_limits<float>::infinity() || value == -std::numeric_limits<float>::infinity())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    if (value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
};

static void convertToTypesFromFloat(const float value){
    if(value >= 32 && value <= 126)
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
        
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min() ||
        value == std::numeric_limits<int>::infinity() || value == -std::numeric_limits<int>::infinity())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

     if (value == std::numeric_limits<float>::infinity() || value == -std::numeric_limits<float>::infinity())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << value << "f" << std::endl;
    
    if (value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(value) << std::endl;
};

static void convertToTypesFromDouble(const double value){
    if(value >= 32 && value <= 126)
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min() ||
        value == std::numeric_limits<int>::infinity() || value == -std::numeric_limits<int>::infinity())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    if (value > std::numeric_limits<float>::max() || value < std::numeric_limits<float>::min() ||
        value == std::numeric_limits<float>::infinity() || value == -std::numeric_limits<float>::infinity())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    
    if (value == std::numeric_limits<double>::infinity() || value == -std::numeric_limits<double>::infinity())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << value << std::endl;
};

void ScalarConverter::convert(const char* input){
    try{
        std::string value(input);
        if (isSpecialCase(value)) {
            convertToTypesFromSpecial(value);
        } else if (isChar(value)) {
            convertToTypesFromChar(value[1]);
        } else if (isInt(value)) {
            convertToTypesFromInt(std::atoi(input));
        } else if (isFloat(value)) {
            convertToTypesFromFloat(std::atof(input));
        } else if (isDouble(value)) {
            convertToTypesFromDouble(std::atof(input));
        } else {
            throw ScalarConverter::InvalidValueToConvert();
        }
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }
};