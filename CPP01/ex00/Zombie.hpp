/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:16:52 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/24 17:55:05 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie{

    public:
        Zombie(void);
        ~Zombie(void);
        
        void announce( void );
        void setName(std::string name);

        static Zombie* newZombie( std::string name );
        static void randomChump( std::string name );

    private:
        std::string _name;

};

#endif