#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <deque>
#include <cerrno>
#include <memory>
#include <cstddef>
#include <sys/time.h>

typedef struct s_pair
{
    int small;
    int big;
    size_t idx;
}   t_pair;

void parse(const char *value, std::vector<int>& vec);

void checkSorting(std::vector<int> &vec, std::deque<int> &deq);

#include "prints.tpp"
#include "ford-jhonson.tpp"

#endif