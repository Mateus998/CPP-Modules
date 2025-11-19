#include "main.hpp"

void addContact(){
    // loop para recolhe de cada um dos dados e adicionar contato no final
}
void searchContact(){
    // tabela de contatos e input do index do contato
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
            addContact();
        else if (input == "SEARCH")
            searchContact();
        else if (input == "EXIT")
            return 0;
    }
    return 0;
}