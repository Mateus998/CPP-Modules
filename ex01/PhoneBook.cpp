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

bool PhoneBook::getContact(int index, Contact *ct){
    if (index >= 0 && index < this->_numberOfContacts){
        *ct = this->_contacts[index];
        return true;
    }
    else if (this->_numberOfContacts == 0)
        std::cout << "Empty Phonebook try 'ADD' some contacts\n";
    else{
        std::cout << "Invalid index: " << index
        << "\nAvailable range: 0 to " << this->_numberOfContacts << "\n";
    }
    return false;
}

void PhoneBook::addContact(Contact cp){
    int numCont = this->_numberOfContacts;
    Contact *conts = this->_contacts;
    if (numCont != 0)
    {
        for (int i = numCont - 1; i >= 0; --i){
            if (i != BOOKSIZE - 1)
                conts[i + 1] = conts[i];
        }
    }
    conts[0] = cp;
    this->_numberOfContacts++;
    std::cout << "Contact added (" << numCont << "/8)\n";
}