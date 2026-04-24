#include "pmergeme.hpp"

template < template <class, class> class C >
struct Cont
{
    typedef C<size_t, std::allocator<size_t> > size_tCont;
    typedef C<bool, std::allocator<bool> > boolCont;
    typedef C<int,    std::allocator<int>    > intCont;
    typedef C<intCont,    std::allocator<intCont>    > pairCont;
};

template < template <class, class> class C >
typename Cont<C>::pairCont::iterator findPositionByBinarySearch(
    typename Cont<C>::pairCont &mainChain,
    typename Cont<C>::pairCont::iterator &limit,
    size_t order, 
    int big)
{
    typedef typename Cont<C>::pairCont::iterator It;

    It left = mainChain.begin();
    It right = limit;

    while(left != right)
    {
        It mid = left + (right - left) / 2;
        int mainBig = (*mid)[order - 1];

        if (mainBig < big)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

template < template <class, class> class C >
typename Cont<C>::size_tCont buildJacobsthalUpTo(size_t max)
{
    /*J(0)=0
    J(1)=1
    J(n)=J(n-1) + 2*J(n-2)*/

    typedef typename Cont<C>::size_tCont IdxCont;

    IdxCont jacob;
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
typename Cont<C>::size_tCont buildInsertionOrderFromJacob( // .............make it simple...........
    size_t max)
{
    typedef typename Cont<C>::size_tCont IdxCont;
    typedef typename Cont<C>::boolCont BoolCont;

    // generate jacobsthal sequence
    IdxCont jacob = buildJacobsthalUpTo<C>(max);
    IdxCont order;
    BoolCont inserted(max, false);

    for(size_t k = 2; k <= jacob.size() - 1; k++)
    {
        size_t start = jacob[k - 1];
        size_t end = std::min(static_cast<size_t>(jacob[k]), max);

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
void orderPairsByBig(
    typename Cont<C>::intCont &container,
    size_t group_count,
    size_t order,
    size_t pair_size)
{
    typedef typename Cont<C>::intCont::iterator It;

    for (size_t i = 0; i < group_count; i++)
    {
        size_t idx_a = i * pair_size; //begin of group A (biggers) inside a pair
        size_t idx_b = idx_a + order; //begin of group B (smallers) inside the same pair

        int val_a = container[idx_a + order - 1]; //first value of group A
        int val_b = container[idx_b + order - 1]; //first value of group B
        
        if (val_b > val_a)
        {
            // order is the size of groups A and B. Half of pair size
            It firstA = container.begin() + idx_a;
            It firstB = container.begin() + idx_b;
            It lastA = firstB;
            // swap values of group A and B of a pair
            std::swap_ranges(firstA, lastA, firstB);
        }
    }
}

template < template <class, class> class C >
void mainChainAndPendFill(
    typename Cont<C>::intCont &container,
    typename Cont<C>::pairCont &mainChain,
    typename Cont<C>::pairCont &pend,
    size_t group_count,
    size_t order,
    size_t pair_size)
{
    typedef typename Cont<C>::intCont IntCont;
    typedef typename IntCont::iterator It;

    for (size_t i = 0; i < group_count; i++)
    {
        size_t idx_a = i * pair_size; //begin of group A (biggers) inside a pair
        size_t idx_b = i * pair_size + order; //begin of group B (smallers) inside the same pair

        It firstA = container.begin() + idx_a;
        It firstB = container.begin() + idx_b;
        
        mainChain.push_back(IntCont(firstA, firstA + order));
        pend.push_back(IntCont(firstB, firstB + order));
    }
}

template < template <class, class> class C >
void insertPendInMainByInsertionOrder(
    typename Cont<C>::pairCont &mainChain,
    typename Cont<C>::pairCont &mainStart,
    typename Cont<C>::pairCont &pend,
    typename Cont<C>::size_tCont &insertOrder,
    size_t order)
{
    typedef typename Cont<C>::intCont IntCont;
    typedef typename Cont<C>::pairCont::iterator PIt;

    for (size_t i = 0; i < insertOrder.size(); i++)
    {
        size_t idx = insertOrder[i];
        IntCont group = pend[idx];
        int big = group[order - 1]; // biggest element of group

        // pend[idx] is the original B(idx+2) because B1 was already removed;
        // its A partner is mainStart[idx+1].
        // the straggler (last pend element) has no A partner: search the full chain.
        PIt limit;
        if (idx + 1 < mainStart.size())
            limit = std::find(mainChain.begin(), mainChain.end(), mainStart[idx + 1]);
        else
            limit = mainChain.end();
        PIt pos = findPositionByBinarySearch<C>(mainChain, limit, order, big);
        mainChain.insert(pos, group);
    }
}

template < template <class, class> class C >
void fordJhonsonSortByBig(
    typename Cont<C>::intCont &container,
    size_t order)
{
    typedef typename Cont<C>::size_tCont IdxCont;
    typedef typename Cont<C>::intCont IntCont;
    typedef typename Cont<C>::pairCont PairCont;
    typedef typename PairCont::iterator PIt;

    size_t total_elem = container.size();
    size_t pair_size = order * 2;
    size_t group_count = total_elem / pair_size;

    // end of the recursion. there are no more pairs of pairs
    if (group_count < 1)
        return;

    // the leftover pair on odd number of groups pf pairs
    size_t remaining = total_elem - group_count * pair_size;
    bool hasStraggler = remaining >= order;

    // order each group of pairs by bigger value
    orderPairsByBig<C>(container, group_count, order, pair_size);

    IntCont straggler;
    if (hasStraggler)
    {
        size_t idx = group_count * pair_size;
        straggler = IntCont(container.begin() + idx, container.begin() + idx + order);
    }
    // go to next level of pairs
    fordJhonsonSortByBig<C>(container, order * 2);

    // creation of mainChain and pend
    PairCont mainChain; // container of groups A of pairs
    PairCont pend; // container of groups B of pairs
    mainChainAndPendFill<C>(container, mainChain, pend, group_count, order, pair_size);

    //copy of starting main
    PairCont mainStart(mainChain);

    if(hasStraggler)
        pend.push_back(straggler);

    // B1 is allways smaller than A1
    mainChain.insert(mainChain.begin(), pend.front());
    pend.erase(pend.begin());

    // generate insertion order based on jacobsthal sequence
    IdxCont insertOrder = buildInsertionOrderFromJacob<C>(pend.size());

    // insert each group of pend in mainChain by insertion order
    insertPendInMainByInsertionOrder<C>(mainChain, mainStart, pend, insertOrder, order);

    IntCont result;
    for(PIt pt = mainChain.begin(); pt != mainChain.end(); pt++)
    {
        result.insert(result.end(), (*pt).begin(), (*pt).end());
    }

    container = result;
}

template < template <class, class> class C >
void pmergeSort(typename Cont<C>::intCont &c, long *microseconds)
{
    struct timeval start, end;

    gettimeofday(&start, NULL);
    fordJhonsonSortByBig<C>(c, 1);
    gettimeofday(&end, NULL);

    *microseconds = (end.tv_sec - start.tv_sec) * 1000000L
                    + (end.tv_usec - start.tv_usec);
}