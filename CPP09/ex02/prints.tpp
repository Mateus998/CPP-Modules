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

template <typename PairCont>
void print_big_numbers(const std::string& info, PairCont& c)
{
    std::cout << info;
    typename PairCont::iterator it = c.begin();
    for (; it != c.end(); it++)
    {
        std::cout << it->big;
        if(it != c.end() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

template <typename Cont>
void checkSorting(Cont &c)
{
    typename Cont::iterator i;
    typename Cont::iterator ii;

    for(i = c.begin(); i != c.end(); i++)
    {
        for(ii = i; ii != c.end(); ii++)
        {
            if(*i > *ii)
            {
                std::cout << "KO" << std::endl; 
                return;
            }
        }
    }

    std::cout << "OK" << std::endl;
}

template <typename PairCont>
void checkSortingPairs(PairCont &c)
{
    typename PairCont::iterator i;
    typename PairCont::iterator ii;

    for(i = c.begin(); i != c.end(); i++)
    {
        for(ii = i; ii != c.end(); ii++)
        {
            if(i->big > ii->big)
            {
                std::cout << "KO" << std::endl; 
                return;
            }
        }
    }

    std::cout << "OK" << std::endl;
}