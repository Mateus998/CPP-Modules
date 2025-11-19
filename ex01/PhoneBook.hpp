#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "main.hpp"
#define BOOKSIZE 8

class PhoneBook {
    public:
    PhoneBook(void);
    ~PhoneBook(void);

    int getContactsNum(void) const;
    Contact getContact(int index) const;

    void addContact(Contact ct);

    private:
    Contact _contacts[BOOKSIZE];
    int _numberOfContacts;
};

#endif