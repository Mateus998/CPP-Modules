/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:32:09 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/27 19:30:56 by mateferr         ###   ########.fr       */
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
    
        bool openRead(void);
        bool openWrite(void);
        void closeFile(void) const;
        std::fstream& getStream(void);
        
    private:
        std::string _fileName;
        std::fstream _fs;
};

#endif