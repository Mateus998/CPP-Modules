/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:49:59 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/28 17:22:41 by mateferr         ###   ########.fr       */
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
        
        void processFiles(std::fstream& input, std::fstream& output);

        private:
        std::string _s1;
        std::string _s2;
        std::string _fstreamToString(std::fstream& fs);
        std::string _replaceString(std::string input);
};

#endif
