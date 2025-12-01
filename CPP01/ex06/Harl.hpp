/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:09:10 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/01 12:46:33 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <map>

class Harl{
    public:
        enum Level{
            UNKNOWN = -1,
            DEBUG = 0,
            INFO = 1,
            WARNING = 2,
            ERROR = 3,
        };
        
        Harl(void);
        ~Harl(void);
        
        Level argToLevel(const std::string arg);
        void complains(const std::string arg);
        
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif
