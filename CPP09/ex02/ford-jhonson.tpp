#include "pmergeme.hpp"

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

    for(size_t k = 2; k <= J.size() - 1; k++)
    {
        size_t start = J[k - 1];
        size_t end = std::min(static_cast<size_t>(J[k]), max);

        for (size_t i = end; i-- > start; )
        {
            if (i < max && !inserted[i])
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
typename Cont<C>::pairCont::iterator findLimitByIdx(typename Cont<C>::pairCont &result, const size_t idx)
{
    typedef typename Cont<C>::pairCont::iterator It;

    It it = result.begin();
    for(; it != result.end(); it++)
    {
        if(it->idx == idx)
            return it;
    }
    return result.end();
}

template < template <class, class> class C >
typename Cont<C>::pairCont::iterator findPositionByBinarySearchByBig(
    typename Cont<C>::pairCont &result,
    t_pair &pendVal)
{
    typedef typename Cont<C>::pairCont::iterator It;

    It biggerIt = findLimitByIdx<C>(result, pendVal.idx);
    It limit = biggerIt != result.end() ? biggerIt + 1 : biggerIt;

    It left = result.begin();
    It right = limit;

    while(left != right)
    {
        It mid = left + (right - left) / 2;
        if (mid->big < pendVal.big)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

template < template <class, class> class C >
void insertSmallersPairsInBiggers(typename Cont<C>::pairCont &result, typename Cont<C>::pairCont &toInsert)
{
    typedef typename Cont<C>::size_tCont Size_tCont;
    typedef typename Cont<C>::pairCont::iterator It;

    Size_tCont insertOrder = buildInsertionOrderFromJacob<C>(toInsert.size());

    for(size_t i = 0; i < insertOrder.size(); i++)
    {
        size_t idx = insertOrder[i];
        It pos = findPositionByBinarySearchByBig<C>(result, toInsert[idx]);
        result.insert(pos, toInsert[idx]);
    }
}

template < template <class, class> class C >
void separateBiggersFromSmallers(
    typename Cont<C>::pairCont &pairs,
    typename Cont<C>::pairCont &biggers,
    typename Cont<C>::pairCont &smallers)
{
    typedef typename Cont<C>::pairCont::iterator It;

    size_t idx = 0;
    for(It it = pairs.begin(); it != pairs.end(); idx++)
    {
        It next = it;
        ++next;
        if(next == pairs.end()) break;

        t_pair big = (*it).big > (*next).big ? *it : *next;
        t_pair small = (*it).big <= (*next).big ? *it : *next;
        big.idx = idx;
        small.idx = idx;

        biggers.push_back(big);
        smallers.push_back(small);

        it = next;
        ++it;
    }
}

template < template <class, class> class C >
void recursionSortPairsByBig(typename Cont<C>::pairCont &pairs)
{
    typedef typename Cont<C>::pairCont PairCont;

    if (pairs.size() <= 1)
        return;

    PairCont biggers;
    PairCont smallers;
    bool hasStraggler = pairs.size() % 2 != 0 ? true : false;

    separateBiggersFromSmallers<C>(pairs, biggers, smallers);

    t_pair straggler;
    if(hasStraggler)
        straggler = pairs.back();

    recursionSortPairsByBig<C>(biggers);

    if(hasStraggler)
        smallers.push_back(straggler);

    insertSmallersPairsInBiggers<C>(biggers, smallers);

    pairs = biggers;
}

template < template <class, class> class C >
void fillPairContainer(
    typename Cont<C>::intCont &c,
    typename Cont<C>::pairCont &pairs)
{
    typedef typename Cont<C>::intCont::iterator It;

    for(It it = c.begin(); it != c.end();)
    {
        It next = it;
        ++next;
        if(next == c.end()) break;

        t_pair p;
        p.big = *it > *next ? *it : *next;
        p.small = *it <= *next ? *it : *next;
        p.idx = 0;
        pairs.push_back(p);

        it = next;
        ++it;
    }
}

template < template <class, class> class C >
void fordJhonsonSortByBig(
    typename Cont<C>::intCont &container)
{
    typedef typename Cont<C>::pairCont PairCont;
    typedef typename Cont<C>::pairCont::iterator ItP;

    PairCont pairs;
    bool hasStraggler = container.size() % 2 != 0 ? true : false;

    fillPairContainer<C>(container, pairs);

    recursionSortPairsByBig<C>(pairs);

    for(size_t i = 0; i < pairs.size(); i++)
        pairs[i].idx = i;

    PairCont biggers(pairs);
    PairCont smallers(pairs);
    for(size_t i = 0; i < pairs.size(); i++)
    {
        biggers[i].small = 0;
        smallers[i].big = smallers[i].small;
        smallers[i].small = 0;
    }

    if(hasStraggler)
    {
        t_pair straggler;
        straggler.big = container.back();
        straggler.small = 0;
        straggler.idx = smallers.size();
        smallers.push_back(straggler);
    }
    
    print_big_numbers< std::vector<t_pair> >("biggers : ", biggers);
    print_big_numbers< std::vector<t_pair> >("smallers: ", smallers);

    checkSortingPairs< std::vector<t_pair> >(biggers);

    insertSmallersPairsInBiggers<C>(biggers, smallers);

    container.clear();
    for(ItP it = biggers.begin(); it != biggers.end(); it++)
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