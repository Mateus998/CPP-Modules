/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:15:49 by mateferr          #+#    #+#             */
/*   Updated: 2026/04/01 18:05:40 by mateferr         ###   ########.fr       */
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

static bool isSpecialCase(std::string& value){
    if (value.empty())
        throw ScalarConverter::InvalidValueToConvert("Empty value");
    for(size_t i = 0; i < value.size(); i++)
        value[i] = std::tolower(value[i]);
        
    if (value == "-inf" || value == "+inf" || value == "inf")
        return true;
    if (value == "-inff" || value == "+inff" || value == "inff")
        return true;
    if (value == "-nan" || value == "+nan" || value == "nan")
        return true;
    if (value == "-nanf" || value == "+nanf" || value == "nanf")
        return true;
    return false;
}

static bool isInt(const std::string& value, int& num){
    errno = 0;
    char* end = 0;
    long v = std::strtol(value.c_str(), &end, 10);
    
    if(std::string(end) != "\0") return false;
    if(errno == ERANGE) return false;
    if(v > INT_MAX || v < INT_MIN) return false;
    num = static_cast<int>(v);
    return true;
}

static bool isFloat(const std::string& value, double& num){
    errno = 0;
    char* end = 0;
    double v = std::strtod(value.c_str(), &end);

    if(std::string(end) != "f") return false;
    if(errno == ERANGE) return false;
    if(v > FLT_MAX || v < -FLT_MAX) return false;
    num = v;
    return true;
}

static bool isDouble(const std::string& value, double& num){
    errno = 0;
    char* end = 0;
    double v = std::strtod(value.c_str(), &end);

    if(std::string(end) != "\0") return false;
    if(errno == ERANGE) throw ScalarConverter::InvalidValueToConvert("Number out of range");
    num = v;
    return true;
}

static bool isChar(const std::string& value){
    if (value.length() == 3 && value[0] == '\'' && value[value.length() - 1] == '\'')
        return true;
    return false;
};

static void convertToTypesFromSpecial(const std::string& value){
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    std::string v;
    if (value == "-nanf" || value == "+nanf" || value == "nanf" || value == "-nan" || value == "+nan")
        v = "nan";
    else if (value == "-inff")
        v = "-inf";
    else if (value == "+inff" || value == "inff" || value == "inf")
        v = "+inf";
    else
        v = value;
    
    std::cout << "float: " << v << "f" << std::endl;
    std::cout << "double: " << v << std::endl;
};

static void convertToTypesFromChar(const char value){
    if(value >= 32 && value <= 126)
        std::cout << "char: " << value << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(value) << std::endl;
    std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(value) << std::endl;
};

static void convertToTypesFromInt(const int value){
    if(value >= 32 && value <= 126)
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << value << std::endl;
    
    std::cout << "float: " << static_cast<float>(value) << ".0f" << std::endl;
    
    std::cout << "double: " << static_cast<double>(value) << ".0" << std::endl;
};

static void convertToTypesFromFloat(const float value){
    if(value >= 32 && value <= 126)
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
        
    if (value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    std::cout << "float: " << value << "f" << std::endl;
    
    std::cout << "double: " << static_cast<double>(value) << std::endl;
};

static void convertToTypesFromDouble(const double value){
    if(value >= 32 && value <= 126)
        std::cout << "char: " << static_cast<char>(value) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    if (value > INT_MAX || value < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    
    if (value > FLT_MAX || value < -FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    
    std::cout << "double: " << value << std::endl;
};

void ScalarConverter::convert(const char* input){
    try{
        std::string value(input);
        int inum;
        double dnum;
        if (isSpecialCase(value)) {
            convertToTypesFromSpecial(value);
        } else if (isChar(value)) {
            convertToTypesFromChar(value[1]);
        } else if (isInt(value, inum)) {
            convertToTypesFromInt(inum);
        } else if (isFloat(value, dnum)) {
            convertToTypesFromFloat(static_cast<float>(dnum));
        } else if (isDouble(value, dnum)) {
            convertToTypesFromDouble(dnum);
        } else {
            throw ScalarConverter::InvalidValueToConvert();
        }
    }
    catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }
};