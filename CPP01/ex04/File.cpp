/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:20 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/10 11:23:09 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File(std::string name):_fileName(name){}

File::~File(void){
    closeFile();
}

bool File::openStreams(void){
    _ifs.open(_fileName.c_str(), std::ios::in);
    if (!_ifs.is_open())
        return std::cerr << "Error opening read file\n", false;
    _ofs.open((_fileName + ".replace").c_str(), std::ios::out | std::ios::trunc);
    if (!_ofs.is_open())
        return std::cerr << "Error opening write file\n", false;
    return true;
}

std::ifstream& File::getIstream(void){
    return _ifs;
}

std::ofstream& File::getOstream(void){
    return _ofs;
}

void File::closeFile(void){
    if (_ifs.is_open())
        _ifs.close();
    if (_ofs.is_open())
        _ofs.close();
}
