/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:25 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:49:00 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
    public:
        FragTrap(void);
        FragTrap(std::string name);
        FragTrap(const FragTrap& copy);
        ~FragTrap(void);
        FragTrap& operator=(const FragTrap& copy);
        void highFivesGuys(void);
};

#endif
