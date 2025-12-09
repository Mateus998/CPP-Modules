/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:44:00 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:40 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{
    protected:
        std::string type;
    public:
        WrongAnimal(void);
        WrongAnimal(const WrongAnimal& a);
        virtual ~WrongAnimal(void);
        WrongAnimal& operator=(const WrongAnimal& a);

        void makeSound(void) const;
};

#endif