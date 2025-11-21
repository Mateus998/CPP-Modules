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