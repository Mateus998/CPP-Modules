#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
    public:
        std::string ideas[100];
        Brain(void);
        Brain(const Brain& d);
        ~Brain(void);
        Brain& operator=(const Brain& d);
        void setIdea(const std::string& ideas);
};

#endif