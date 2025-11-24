/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:10:44 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/24 17:14:53 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

#include <string>
#include <iostream>
#include <limits>
#include <sstream>
#include <cstdlib>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void addContact(PhoneBook *book);

std::string intToString(int i);
bool stringToInt(std::string str, int *i);

void searchContact(PhoneBook *book);

#endif