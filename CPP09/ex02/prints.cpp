#include "pmergeme.hpp"

void print_numbers(const std::string& info, const std::vector<int>& vec)
{
    std::cout << info;
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it;
        if(it != vec.end() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}