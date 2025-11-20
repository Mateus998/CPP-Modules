#include "main.hpp"

void inputInfo(Contact *ct, std::string msg, bool (Contact::*setFunc)(std::string)){
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
    inputInfo(&contact, "Fist name:\n", &Contact::setFirstName);
    inputInfo(&contact, "Last name:\n", &Contact::setLastName);
    inputInfo(&contact, "Nickname:\n", &Contact::setNickname);
    inputInfo(&contact, "Phone number:\n", &Contact::setNumber);
    inputInfo(&contact, "Darkest secret:\n", &Contact::setSecret);
    book->addContact(contact); //count atrasado
}

void formatSearch(std::string s){ //change '.'
    for (std::size_t i = 0; i < 10; ++i){
        if (i < s.size()){
            if (i == 9)
                std::cout << '.';
            else
                std::cout << s[i];
        }
        else
            std::cout << ' ';
    }
    std::cout << '|';
}

std::string intToString(int i){
    std::ostringstream ostr;
    ostr << i;
    return ostr.str();
}

int stringToInt(std::string str){ //proteger
    int i;
    std::istringstream istr(str);
    istr >> i;
    return i;
}

void searchContact(PhoneBook *book){ //change if is empty
    Contact ct;
    std::cout << '|';
    formatSearch("Index");
    formatSearch("First name");
    formatSearch("Last name");
    formatSearch("Nickname");
    std::cout << "\n|";
    for (int i = 0; i < book->getContactsNum(); ++i){
        book->getContact(i, &ct);
        formatSearch(intToString(i));
        formatSearch(ct.getFirstName());
        formatSearch(ct.getLastName());
        formatSearch(ct.getNickname());
        std::cout << '\n';
        if (i < book->getContactsNum() - 1)
            std::cout << '|';
    }
    std::cout << '\n';
    std::string input;
    while(true){ //infinito se vazio
        std::cout << "Contact Index:\n";
        if (!std::getline(std::cin, input)){
            std::cin.clear();
            // std::cin.ignore(std::numeric_limitsstd::streamsize::max(), '\n');
            continue;
        }
        if (book->getContact(stringToInt(input), &ct))
            break;
    }
    //nomear prints
    std::cout << ct.getFirstName() << '\n';
    std::cout << ct.getLastName() << '\n';
    std::cout << ct.getNickname() << '\n';
    std::cout << ct.getNumber() << '\n';
    std::cout << ct.getSecret() << '\n';
}

int main(){
    PhoneBook book;
    std::string input;

    while(true){
        std::cout << "My Awesome PhoneBook!\nADD; SEARCH; EXIT\n";
        if (!std::getline(std::cin, input)){
            std::cin.clear();
            // std::cin.ignore(std::numeric_limitsstd::streamsize::max(), '\n');
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