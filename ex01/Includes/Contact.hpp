#ifndef CONTACT_HPP
# define CONTACT_HPP

#include "main.hpp"

class Contact{
    public:
    Contact(void);
    ~Contact(void);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getNumber() const;
    std::string getSecret() const;

    bool setFirstName(std::string s);
    bool setLastName(std::string s);
    bool setNickname(std::string s);
    bool setNumber(std::string s);
    bool setSecret(std::string s);

    static bool isdigitStr(std::string s);

    private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
    
    static bool _isalphaStr(std::string s);
    static bool _isnickStr(std::string s);
    static bool _istextStr(std::string s);
};

#endif