/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:13 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:50 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal{
    protected:
        std::string type;
    public:
        AAnimal(void);
        AAnimal(const AAnimal& a);
        virtual ~AAnimal(void) = 0;
        AAnimal& operator=(const AAnimal& a);

        virtual void makeSound(void);
};

#endif