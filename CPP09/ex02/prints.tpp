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
void print_pairs(const std::string& info, PairCont& c)
{
    std::cout << info;
    typename PairCont::iterator it = c.begin();
    for (; it != c.end(); it++)
    {
        std::cout << it->big << " " << it->small;
        if(it != c.end() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}