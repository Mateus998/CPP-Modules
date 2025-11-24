/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addContact.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:10:53 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/24 17:14:58 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/main.hpp"

static void setContactInfo(Contact *ct, std::string msg, bool (Contact::*setFunc)(std::string)){
    std::string input;
    while(true){
        std::cout << msg;
        if (!std::getline(std::cin, input)){
            if (std::cin.eof() || std::cin.bad())
                exit(1);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if ((ct->*setFunc)(input))
            break;
    }
}

void addContact(PhoneBook *book){
    Contact contact;
    setContactInfo(&contact, "Fist name:\n", &Contact::setFirstName);
    setContactInfo(&contact, "Last name:\n", &Contact::setLastName);
    setContactInfo(&contact, "Nickname:\n", &Contact::setNickname);
    setContactInfo(&contact, "Phone number:\n", &Contact::setNumber);
    setContactInfo(&contact, "Darkest secret:\n", &Contact::setSecret);
    book->addContact(contact);
}