#include "../Includes/main.hpp"

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

int PhoneBook::getContact(int index, Contact *ct){
    if (index >= 0 && index < this->_numberOfContacts){
        *ct = this->_contacts[index];
        return 1;
    }
    else if (this->isEmpty()){
        return 2;
    }
    else{
        std::cout << "Invalid index: " << index + 1
        << "\nAvailable range: 1 to " << this->_numberOfContacts << "\n";
        return 0;
    }
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
    if (numCont < BOOKSIZE)
        this->_numberOfContacts++;
    std::cout << "\nContact added (" << this->_numberOfContacts << "/8)\n";
}

bool PhoneBook::isEmpty(){
    if(this->_numberOfContacts == 0){
        std::cout << "Empty Phonebook try 'ADD' some contacts\n";
        return true;
    }
    return false;
}