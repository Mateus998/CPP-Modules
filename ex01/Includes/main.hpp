#ifndef MAIN_HPP
# define MAIN_HPP

#include <string>
#include <iostream>
#include <limits>
#include <sstream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void addContact(PhoneBook *book);

std::string intToString(int i);
bool stringToInt(std::string str, int *i);

void searchContact(PhoneBook *book);

#endif