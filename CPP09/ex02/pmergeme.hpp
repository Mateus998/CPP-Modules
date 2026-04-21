#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <deque>

typedef struct s_pair
{
    int small;
    int big;
    size_t idx;
}   t_pair;

// typedef struct s_time
// {

// } t_time;

void parse(const char *value, std::vector<int>& vec);

template <typename Cont, typename PairCont>
void pmergeSort(Cont &c);

#include "ford-jhonson.tpp"
#include "prints.tpp"

#endif