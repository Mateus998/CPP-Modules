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

//############################################################################ prints template

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

//################################################################### sorting algorithm templates

template < template <class, class> class C >
struct Cont
{
    typedef C<size_t, std::allocator<size_t> > size_tCont;
    typedef C<bool,   std::allocator<bool>   > boolCont;
    typedef C<int,    std::allocator<int>    > intCont;
    typedef C<t_pair, std::allocator<t_pair> > pairCont;
};

template < template <class, class> class C >
typename Cont<C>::size_tCont buildJacobsthalUpTo(size_t max)
{
    /*J(0)=0
    J(1)=1
    J(n)=J(n-1) + 2*J(n-2)*/

    typedef typename Cont<C>::size_tCont Size_tCont;

    Size_tCont jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while(jacob.back() < max)
    {
        size_t n = jacob.size();
        jacob.push_back(jacob[n - 1] + 2 * jacob[n - 2]);
    }
    return jacob;
}

template < template <class, class> class C >
typename Cont<C>::size_tCont buildInsertionOrderFromJacob(size_t max)
{
    typedef typename Cont<C>::size_tCont Size_tCont;
    typedef typename Cont<C>::boolCont BoolCont;

    Size_tCont order;
    BoolCont inserted(max, false);
    Size_tCont J = buildJacobsthalUpTo<C>(max);

    for(size_t k = 2; k < J.size(); k++)
    {
        size_t start = J[k - 1];
        size_t end = std::min(J[k], max);

        for (size_t i = end; i-- > start; )
        {
            if (!inserted[i])
            {
                order.push_back(i);
                inserted[i] = true;
            }
        }
    }

    for(size_t i = 0; i < max; i++)
        if(!inserted[i])
            order.push_back(i);
    
    return order;
}

template < template <class, class> class C >
typename Cont<C>::pairCont::iterator findByIdx(
    typename Cont<C>::pairCont &result, const size_t target)
{
    typedef typename Cont<C>::pairCont::iterator It;

    It it = result.begin();
    for(; it != result.end(); it++)
    {
        if(it->idx == target)
            return it;
    }
    return result.end();
}

template < template <class, class> class C >
typename Cont<C>::pairCont::iterator findPositionByBinarySearch(
    typename Cont<C>::pairCont &result,
    typename Cont<C>::pairCont::iterator limit,
    int value)
{
    typedef typename Cont<C>::pairCont::iterator It;

    It left = result.begin();
    It right = limit;

    while(left != right)
    {
        It mid = left + (right - left) / 2;
        if (mid->big < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

template < template <class, class> class C >
void insertSmallersPairsInBiggers(
    typename Cont<C>::pairCont &result,
    typename Cont<C>::pairCont &pending)
{
    typedef typename Cont<C>::size_tCont Size_tCont;
    typedef typename Cont<C>::pairCont::iterator It;

    Size_tCont insertOrder = buildInsertionOrderFromJacob<C>(pending.size());

    for(size_t i = 0; i < insertOrder.size(); i++)
    {
        size_t idx = insertOrder[i];
        t_pair &elem = pending[idx];
        It bound = findByIdx<C>(result, elem.idx);
        It limit = (bound != result.end()) ? bound + 1 : result.end();
        It pos = findPositionByBinarySearch<C>(result, limit, elem.big);
        result.insert(pos, elem);
    }
}

template < template <class, class> class C >
void separateBiggersFromSmallers(
    typename Cont<C>::pairCont &pairs,
    typename Cont<C>::pairCont &biggers,
    typename Cont<C>::pairCont &smallers)
{
    for (size_t i = 0; i + 1 < pairs.size(); i += 2)
    {
        t_pair &a = pairs[i];
        t_pair &b = pairs[i + 1];
        size_t  k = i / 2;

        a.idx = k;
        b.idx = k;

        (a.big >= b.big) ? biggers.push_back(a) : biggers.push_back(b);
        (a.big < b.big) ? smallers.push_back(a) : smallers.push_back(b);
    
    }
}

template < template <class, class> class C >
void restoreIdxValueToOrigin(
    typename Cont<C>::intCont &origBigs,
    typename Cont<C>::pairCont &biggers)
{
    typedef typename Cont<C>::boolCont BoolCont;

    BoolCont matched(origBigs.size(), false);
    for (size_t p = 0; p < biggers.size(); p++)
    {
        for (size_t k = 0; k < origBigs.size(); k++)
        {
            if (!matched[k] && origBigs[k] == biggers[p].big)
            {
                biggers[p].idx = k;
                matched[k]     = true;
                break;
            }
        }
    }
}

template < template <class, class> class C >
void recursionSortPairsByBig(typename Cont<C>::pairCont &pairs)
{
    typedef typename Cont<C>::pairCont PairCont;
    typedef typename Cont<C>::intCont IntCont;

    if (pairs.size() <= 1)
        return;

    PairCont biggers, smallers;
    bool hasStraggler = (pairs.size() % 2 != 0);
    t_pair straggler = pairs.back();

    separateBiggersFromSmallers<C>(pairs, biggers, smallers);

    // Save big values before the recursive call corrupts idx
    IntCont origBigs;
    for (size_t i = 0; i < biggers.size(); i++)
        origBigs.push_back(biggers[i].big);

    recursionSortPairsByBig<C>(biggers);

    restoreIdxValueToOrigin<C>(origBigs, biggers);

    if(hasStraggler)
    {
        straggler.idx = biggers.size();
        smallers.push_back(straggler);
    }

    insertSmallersPairsInBiggers<C>(biggers, smallers);

    pairs = biggers;
}

template < template <class, class> class C >
void fillPairContainer(
    typename Cont<C>::intCont &c,
    typename Cont<C>::pairCont &pairs)
{
    for (size_t i = 0; i + 1 < c.size(); i += 2)
    {
        int    a = c[i], b = c[i + 1];
        t_pair p;
        p.big   = (a >= b) ? a : b;
        p.small = (a >= b) ? b : a;
        p.idx   = 0;
        pairs.push_back(p);
    }
}

template < template <class, class> class C >
void fordJhonsonSortByBig(
    typename Cont<C>::intCont &container)
{
    typedef typename Cont<C>::pairCont PairCont;
    typedef typename Cont<C>::pairCont::iterator It;

    PairCont pairs;
    bool hasStraggler = (container.size() % 2 != 0);
    int  straggler    = container.back();

    fillPairContainer<C>(container, pairs);

    recursionSortPairsByBig<C>(pairs);

    // Re-index so that result[i].idx == i == pending[i].idx
    for(size_t i = 0; i < pairs.size(); i++)
        pairs[i].idx = i;

    PairCont biggers(pairs), smallers(pairs);
    for(size_t i = 0; i < pairs.size(); i++)
    {
        biggers[i].small = 0;
        smallers[i].big = smallers[i].small;
        smallers[i].small = 0;
    }

    if(hasStraggler)
    {
        t_pair stg;
        stg.big = straggler;
        stg.small = 0;
        stg.idx = biggers.size();
        smallers.push_back(stg);
    }

    insertSmallersPairsInBiggers<C>(biggers, smallers);

    container.clear();
    for(It it = biggers.begin(); it != biggers.end(); it++)
    {
        container.push_back(it->big);
    }
}

template < template <class, class> class C >
void pmergeSort(typename Cont<C>::intCont &c, long *microseconds)
{
    struct timeval start, end;

    gettimeofday(&start, NULL);
    fordJhonsonSortByBig<C>(c);
    gettimeofday(&end, NULL);

    *microseconds = (end.tv_sec - start.tv_sec) * 1000000L
                    + (end.tv_usec - start.tv_usec);
}

#endif