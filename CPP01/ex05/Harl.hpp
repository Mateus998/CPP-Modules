/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:09:10 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:01:54 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl{
    public:
        Harl(void);
        ~Harl(void);
        
        void complain(std::string level);
        
    private:
        void (Harl::*_levels[4])();
        std::string _inputs[4];
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif
