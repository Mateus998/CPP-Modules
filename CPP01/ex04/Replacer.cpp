/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:56:38 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/28 17:25:19 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

Replacer::Replacer(std::string s1, std::string s2){
    this->_s1 = s1;
    this->_s2 = s2;
}

Replacer::~Replacer(void){}

std::string Replacer::_fstreamToString(std::fstream& fs){
    std::ostringstream oss;
    oss << fs.rdbuf();
    std::string string = oss.str();
    return string;
}

std::string Replacer::_replaceString(std::string input){
    std::string output;
    std::size_t pos = 0;
    while(true){
        std::string::size_type found = input.find(_s1, pos);
        if (found == std::string::npos){
            output.append(input, pos, input.size() - pos);
            break;
        }
        output.append(input, pos, found - pos);
        output.append(_s2);
        pos = found + _s1.size();
    }
    return output;
}

void Replacer::processFiles(std::fstream& input, std::fstream& output){
    std::string inputString = _fstreamToString(input);

    std::string outputString = _replaceString(inputString);
    
    output << outputString;
}