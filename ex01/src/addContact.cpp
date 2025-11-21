#include "../Includes/main.hpp"

static void setContactInfo(Contact *ct, std::string msg, bool (Contact::*setFunc)(std::string)){
    std::string input;
    while(true){
        std::cout << msg;
        if (!std::getline(std::cin, input)){
            std::cin.clear();
            // std::cin.ignore(std::numeric_limitsstd::streamsize::max(), '\n');
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