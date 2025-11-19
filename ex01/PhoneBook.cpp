#include "main.hpp"

PhoneBook::PhoneBook(){
    this->_numberOfContacts = 0;
    return;
}

PhoneBook::~PhoneBook(void){
    return;
}

int PhoneBook::getContactsNum(void) const{
    return this->_numberOfContacts;
}

Contact PhoneBook::getContact(int index) const{
    if (index > 0 && index < this->_numberOfContacts)
        return this->_contacts[index];
}

void PhoneBook::addContact(Contact cp){
    int numCont = this->_numberOfContacts;
    Contact *conts = this->_contacts;
    if (numCont != 0)
    {
        for (int i = numCont - 1; i >= 0; --i){
            if (i != BOOKSIZE)
                conts[i + 1] = conts[i];
        }
    }
    conts[0] = cp;
}