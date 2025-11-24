/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:10:48 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/24 17:14:55 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "main.hpp"
#define BOOKSIZE 8

class PhoneBook {
    public:
    PhoneBook(void);
    ~PhoneBook(void);

    int getContactsNum(void) const;
    int getContact(int index, Contact *ct);

    void addContact(Contact ct);

    bool isEmpty();

    private:
    Contact _contacts[BOOKSIZE];
    int _numberOfContacts;
};

#endif