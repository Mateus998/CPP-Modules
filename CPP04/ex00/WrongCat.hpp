/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:43:24 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 17:47:16 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
    public:
        WrongCat(void);
        WrongCat(const WrongCat& d);
        ~WrongCat(void);
        WrongCat& operator=(const WrongCat& d);
        void makeSound(void) const;
        std::string getType(void) const;
};

#endif