/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 09:51:42 by mateferr          #+#    #+#             */
/*   Updated: 2026/04/02 16:48:37 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>{
    public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin(){
        return this->c.begin();
    };
    iterator end(){
        return this->c.end();
    };
    
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator begin() const{
        return this->c.begin();
    };
    const_iterator end() const{
        return this->c.end();
    };
    
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin(){
        return this->c.rbegin();
    };
    reverse_iterator rend(){
        return this->c.rend();
    };
};

#endif