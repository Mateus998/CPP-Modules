/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 23:26:58 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/05 00:02:19 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base{
    public:
    virtual ~Base(void){};
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif