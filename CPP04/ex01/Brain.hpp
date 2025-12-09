/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:43:40 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:23 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
    public:
        std::string ideas[100];
        Brain(void);
        Brain(const Brain& d);
        ~Brain(void);
        Brain& operator=(const Brain& d);
        void setIdea(const std::string& ideas);
};

#endif