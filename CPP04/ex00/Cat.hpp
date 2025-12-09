/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:55 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:07 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{
    public:
        Cat(void);
        Cat(const Cat& d);
        ~Cat(void);
        Cat& operator=(const Cat& d);
        void makeSound(void) const;
        std::string getType(void) const;
};

#endif