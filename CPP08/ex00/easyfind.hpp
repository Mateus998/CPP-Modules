/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 17:54:51 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/05 18:16:32 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>

template<typename T>
typename T::iterator easyfind(T& container, int value){
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
        throw std::runtime_error("Value not found");
    return it;
}

#endif