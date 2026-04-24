#include "pmergeme.hpp"

template <typename Cont>
void print_numbers(const std::string& info, Cont& c)
{
    std::cout << info;
    typename Cont::iterator it = c.begin();
    for (; it != c.end(); it++)
    {
        std::cout << *it;
        if(it != c.end() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}