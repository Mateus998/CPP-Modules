/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchContact.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:11:04 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/24 17:15:02 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/main.hpp"

static void formatSearch(std::string s){
    for (std::size_t i = 0; i < 10; ++i){
        if (i < s.size()){
            if (i == 9 && s.size() > 10)
                std::cout << '.';
            else
                std::cout << s[i];
        }
        else
            std::cout << ' ';
    }
    std::cout << '|';
}

static void searchTable(PhoneBook *book){
    Contact ct;

    std::cout << '|';
    formatSearch("Index");
    formatSearch("First name");
    formatSearch("Last name");
    formatSearch("Nickname");
    std::cout << "\n";
    for (int i = 0; i < book->getContactsNum(); ++i){
        std::cout << '|';
        book->getContact(i, &ct);
        formatSearch(intToString(i + 1));
        formatSearch(ct.getFirstName());
        formatSearch(ct.getLastName());
        formatSearch(ct.getNickname());
        std::cout << '\n';
    }
    std::cout << '\n';
}

static Contact getContactByIndex(PhoneBook *book){
    Contact ct;
    std::string input;

    while(true){
        std::cout << "Contact Index:\n";
        if (!std::getline(std::cin, input)){
            if (std::cin.eof() || std::cin.bad())
                exit(1);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        int idx;
        if (!stringToInt(input, &idx))
            continue;
        if (book->getContact(idx - 1, &ct))
            break;
    }
    return ct;
}

static void printContactInfo(Contact ct){
    std::cout << "Name: " << ct.getFirstName() << ' ' << ct.getLastName() << '\n';
    std::cout << "Nickname: " << ct.getNickname() << '\n';
    std::cout << "Phone number: " << ct.getNumber() << '\n';
    std::cout << "Darkest secret: " << ct.getSecret() << '\n';
}

void searchContact(PhoneBook *book){
    Contact ct;

    searchTable(book);
    if (book->isEmpty())
        return;
    ct = getContactByIndex(book);
    printContactInfo(ct);
}