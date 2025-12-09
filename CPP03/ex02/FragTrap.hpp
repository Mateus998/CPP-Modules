/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:41:54 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:48:50 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        ~FragTrap(void);
        FragTrap& operator=(const FragTrap& copy);
        void highFivesGuys(void);
};

#endif
