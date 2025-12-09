/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:43:03 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:10 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal{
    public:
        Dog(void);
        Dog(const Dog& d);
        ~Dog(void);
        Dog& operator=(const Dog& d);
        void makeSound(void) const;
        std::string getType(void) const;
};

#endif