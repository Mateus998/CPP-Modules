/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arguments.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:36:37 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/27 18:46:41 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Arguments.hpp"

Arguments::Arguments(int argc, char **argv){
    this->_argc = argc;
    this->_argv = argv;
}

Arguments::~Arguments(void){}

bool Arguments::validate(void){
    if (_argc != 4)
        return std::cerr << "3 arguments only\n", false;
    _fileName = _argv[1];
    _s1 = _argv[2];
    _s2 = _argv[3];
    if(_s1.empty())
        return std::cerr << "s1 is empty\n", false;
    return true;
}

std::string Arguments::getFileName(void) const{
    return _fileName;
}

std::string Arguments::getS1(void) const{
    return _s1;
}

std::string Arguments::getS2(void) const{
    return _s2;
}