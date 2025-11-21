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