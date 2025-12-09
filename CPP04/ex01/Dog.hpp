/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:43:51 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:30 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
    public:
        Dog(void);
        Dog(const Dog& d);
        ~Dog(void);
        Dog& operator=(const Dog& d);
        void makeSound(void);
        Brain* getBrain(void) const;
    private:
        Brain* _brain;
};

#endif