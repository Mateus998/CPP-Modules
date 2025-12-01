/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:09:10 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/01 12:45:57 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <map>

class Harl{
    public:
        typedef void (Harl::*Level)(void);
        Harl(void);
        ~Harl(void);
        
        void complain(std::string level);
        
    private:
        std::map<std::string, Level> levels_; 
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif
