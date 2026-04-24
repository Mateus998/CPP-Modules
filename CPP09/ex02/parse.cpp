#include "pmergeme.hpp"

static int convertToInt(const char *value)
{
    errno = 0;
    char* end = 0;
    long v = std::strtol(value, &end, 10);
    
    if(std::string(value).empty()) throw std::logic_error("Empty string");
    if(*end != '\0') throw std::logic_error("Invalid char detected");
    if(end == value) throw std::logic_error("No digits found");
    if(errno == ERANGE) throw std::overflow_error("Out of range of long type");
    if(v > INT_MAX || v < INT_MIN) throw std::overflow_error("out of range of int type");
    
    return static_cast<int>(v);
}

void parse(const char *value, std::vector<int>& vec)
{
    int num = convertToInt(value);
    vec.push_back(num);
}

void checkSorting(std::vector<int> &vec, std::deque<int> &deq)
{
    std::vector<int>::iterator vi;
    std::vector<int>::iterator vii;
    std::deque<int>::iterator di;
    std::deque<int>::iterator dii;

    for(vi = vec.begin(); vi != vec.end(); vi++)
    {
        for(vii = vi; vii != vec.end(); vii++)
        {
            if(*vi > *vii)
            {
                std::cout << "KO" << std::endl; 
                return;
            }
        }
    }

    for(di = deq.begin(); di != deq.end(); di++)
    {
        for(dii = di; dii != deq.end(); dii++)
        {
            if(*di > *dii)
            {
                std::cout << "KO" << std::endl;
                return;
            }
        }
    }

    std::cout << "OK" << std::endl;
}
