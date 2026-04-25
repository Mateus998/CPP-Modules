#include "PmergeMe.hpp"

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