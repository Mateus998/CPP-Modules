/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:49:59 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/10 11:27:10 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

#include "File.hpp"
#include <sstream>

class Replacer{
    public:
        Replacer(std::string s1, std::string s2);
        ~Replacer(void);
        
        bool processFiles(std::ifstream& input, std::ofstream& output);

        private:
        std::string _s1;
        std::string _s2;
        std::string _fstreamToString(std::ifstream& fs);
        std::string _replaceString(std::string input);
};

#endif
