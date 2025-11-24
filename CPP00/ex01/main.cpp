/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:15:55 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/24 17:16:00 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/main.hpp"

int main(){
    PhoneBook book;
    std::string input;

    std::cout << "My Awesome PhoneBook!\n";
    while(true){
        std::cout << "\n'ADD': (add a contact to the list)\n";
        std::cout << "'SEARCH': (search for a contact of the list)\n";
        std::cout << "'EXIT': (exit the program)\n";
        if (!std::getline(std::cin, input)){
            if (std::cin.eof() || std::cin.bad())
                exit(1);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (input == "ADD")
            addContact(&book);
        else if (input == "SEARCH")
            searchContact(&book);
        else if (input == "EXIT")
            return 0;
    }
    return 0;
}