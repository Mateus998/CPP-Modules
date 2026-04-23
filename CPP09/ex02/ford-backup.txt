#include "pmergeme.hpp"

template < template <class, class> class C >
struct Cont
{
    typedef C<size_t, std::allocator<size_t> > size_tCont;
    typedef C<int,    std::allocator<int>    > intCont;
    typedef C<bool,   std::allocator<bool>   > boolCont;
    typedef C<t_pair, std::allocator<t_pair> > pairCont;
};

template < template <class, class> class C >
typename Cont<C>::size_tCont buildJacobsthalUpTo(size_t max) //comecar por 1 e 1 porque o 0 sera sempre inserido diretamente, depois apagar um dos 1
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
typename Cont<C>::pairCont::iterator findByIdx(typename Cont<C>::pairCont &result, const size_t idx)
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

    It biggerIt = findByIdx<C>(result, pendVal.idx);
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
        int idx = insertOrder[i];
        It pos = findPositionByBinarySearchByBig<C>(result, toInsert[idx]);
        result.insert(pos, toInsert[idx]);
    }
}

template < template <class, class> class C >
void insertStragglerPair(typename Cont<C>::pairCont &result, t_pair &straggler)
{
    typedef typename Cont<C>::pairCont::iterator It;

    It pos = findPositionByBinarySearchByBig<C>(result, straggler);
    result.insert(pos, straggler);
}

template < template <class, class> class C >
void fordJhonsonSortPairsByBig(typename Cont<C>::pairCont &pairs)
{
    typedef typename Cont<C>::pairCont PairCont;
    typedef typename PairCont::iterator It;

    if (pairs.size() <= 1)
        return;

    PairCont biggers;
    PairCont smallers;
    bool hasStraggler = false;
    t_pair straggler;

    if(pairs.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = pairs.back();
    }

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

    fordJhonsonSortPairsByBig<C>(biggers);

    PairCont result = biggers;

    insertSmallersPairsInBiggers<C>(result, smallers);

    if(hasStraggler)
        insertStragglerPair<C>(result, straggler);

    pairs = result;
}

template < template <class, class> class C >
void pmergeSort(typename Cont<C>::intCont &c)
{
    typedef typename Cont<C>::intCont IntCont;
    typedef typename Cont<C>::pairCont PairCont;
    typedef typename Cont<C>::intCont::iterator It;
    typedef typename Cont<C>::pairCont::iterator ItP;

    PairCont pairs;
    int straggler = 0;
    bool hasStraggler = false;
    (void)straggler;
    (void)hasStraggler;

    if(c.size() % 2 != 0)
    {
        straggler = c.back();
        hasStraggler = true;
    }

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

    print_pairs("Before: ", pairs);
    fordJhonsonSortPairsByBig<C>(pairs);
    print_pairs("After: ", pairs);

    IntCont chain;
    IntCont pend;
    for(ItP it = pairs.begin(); it != pairs.end(); it++)
    {
        chain.push_back(it->big);
        pend.push_back(it->small);
    }

}

// como gerir o time - unidade e funcao gettime

// copiar file, arquivar e desenvolver nova forma atravez do exemplo .txt