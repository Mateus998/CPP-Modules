/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:32:09 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/10 11:22:00 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

#include <iostream>
#include <fstream>

class File{
    public:
        File(std::string fileName);
        ~File(void);
    
        bool openStreams(void);
        void closeFile(void);
        std::ifstream& getIstream(void);
        std::ofstream& getOstream(void);
        
    private:
        std::string _fileName;
        std::ifstream _ifs;
        std::ofstream _ofs;
};

#endif