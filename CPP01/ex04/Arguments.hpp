/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Arguments.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 18:27:49 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/27 18:36:21 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_HPP
# define ARGUMENTS_HPP

#include <iostream>

class Arguments{
    public:
        Arguments(int argc, char **argv);
        ~Arguments(void);
        
        bool validate(void);
        std::string getS1(void) const;
        std::string getS2(void) const;
        std::string getFileName(void) const;
        
    private:
        std::string _s1; 
        std::string _s2; 
        std::string _fileName; 
        int _argc;
        char** _argv;
};

#endif