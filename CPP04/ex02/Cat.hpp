/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:23 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:56 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
    public:
        Cat(void);
        Cat(const Cat& d);
        ~Cat(void);
        Cat& operator=(const Cat& d);
        void makeSound(void);
        Brain* getBrain(void) const;
    private:
        Brain* _brain;
};

#endif