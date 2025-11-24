/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:10:57 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/24 17:14:59 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/main.hpp"

Contact::Contact(void){
    return;
}

Contact::~Contact(void){
    return;
}

std::string Contact::getFirstName() const{
    return this->_firstName;
}

std::string Contact::getLastName() const{
    return this->_lastName;
}

std::string Contact::getNickname() const{
    return this->_nickname;
}

std::string Contact::getNumber() const{
    return this->_phoneNumber;
}

std::string Contact::getSecret() const{
    return this->_darkestSecret;
}

bool Contact::setFirstName(std::string s){
    if (!_isalphaStr(s))
        return std::cout << s << ": Not a valid name\n", false;
    this->_firstName = s;
    return true;
}
bool Contact::setLastName(std::string s){
    if (!_isalphaStr(s))
        return std::cout << s << ": Not a valid name\n", false;
    this->_lastName = s;
    return true;
}
bool Contact::setNickname(std::string s){
    if (!_isnickStr(s))
        return std::cout << s << ": Not a valid nick name\n", false;
    this->_nickname = s;
    return true;
}
bool Contact::setNumber(std::string s){
    if (!isdigitStr(s))
        return std::cout << s << ": Not a valid number\n", false;
    this->_phoneNumber = s;
    return true;
}
bool Contact::setSecret(std::string s){
    if (!_istextStr(s))
        return std::cout << s << ": Not a valid text\n", false;
    this->_darkestSecret = s;
    return true;
}

bool Contact::_isalphaStr(std::string s){
    if (s.empty())
        return false;
    for (std::string::iterator i = s.begin(); i != s.end(); ++i){
        unsigned char c = static_cast<unsigned char>(*i);
        if (!std::isalpha(c))
            return false;
    }
    return true;
}

bool Contact::isdigitStr(std::string s){
    if (s.empty())
        return false;
    for (std::string::iterator i = s.begin(); i != s.end(); ++i){
        unsigned char c = static_cast<unsigned char>(*i);
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

bool Contact::_isnickStr(std::string s){
    if (s.empty())
        return false;
    for (std::string::iterator i = s.begin(); i != s.end(); ++i){
        unsigned char c = static_cast<unsigned char>(*i);
        if (!std::isprint(c) || std::isspace(c))
            return false;
    }
    return true;
}

bool Contact::_istextStr(std::string s){
    if (s.empty())
        return false;
    for (std::string::iterator i = s.begin(); i != s.end(); ++i){
        unsigned char c = static_cast<unsigned char>(*i);
        if (!std::isprint(c))
            return false;
    }
    return true;
}