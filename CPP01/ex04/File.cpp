/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:20 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/28 14:33:11 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string name):_fileName(name){}

File::~File(void){
    closeFile();
}

bool File::openRead(void){
    _fs.open(_fileName.c_str(), std::ios::in);
    if (!_fs.is_open())
        return std::cerr << "Error opening read file\n", false;
    return true;
}

bool File::openWrite(void){
    _fs.open(_fileName.c_str(), std::ios::out | std::ios::trunc);
    if (!_fs.is_open())
        return std::cerr << "Error opening write file\n", false;
    return true;
}

std::fstream& File::getStream(void){
    return _fs;
}

void File::closeFile(void){
    if (_fs.is_open())
        _fs.close();
}
