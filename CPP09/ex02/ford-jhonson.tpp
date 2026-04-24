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
typename Cont<C>::size_tCont buildInsertionOrderFromJacob(
    typename Cont<C>::size_tCont jacob,
    size_t max)
{ // simplificar para explicar
    typedef typename Cont<C>::size_tCont Size_tCont;
    typedef typename Cont<C>::boolCont BoolCont;

    Size_tCont order;
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
void fordJhonsonSortByBig(
    typename Cont<C>::intCont &container,
    size_t order)
{
    typedef typename Cont<C>::intCont IntCont;
    typedef typename Cont<C>::size_tCont IdxCont;
    typedef typename Cont<C>::pairCont PairCont;
    typedef typename IntCont::iterator It;
    typedef typename PairCont::iterator PIt;

    size_t total_elem = container.size();
    size_t pair_size = order * 2;
    size_t group_count = total_elem / pair_size;

    // end of the recursion. there are no more pairs of pairs
    if (group_count < 1)
        return;

    // the leftover pair on odd number of groups pf pairs
    bool hasStraggler = group_count * pair_size != total_elem;

    // order each group of pairs by bigger value
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

    // go to next level of pairs
    fordJhonsonSortByBig<C>(container, order * 2);

    // creation of mainChain and pend
    PairCont mainChain; // container of groups A of pairs
    PairCont pend; // container of groups B of pairs

    for (size_t i = 0; i < group_count; i++)
    {
        size_t idx_a = i * pair_size; //begin of group A (biggers) inside a pair
        size_t idx_b = idx_a + order; //begin of group B (smallers) inside the same pair

        It firstA = container.begin() + idx_a;
        It lastA = firstA + order;
        It firstB = container.begin() + idx_b;
        It lastB = firstB + order;

        mainChain.push_back(IntCont(firstA, lastA));
        pend.push_back(IntCont(firstB, lastB));
    }

    PairCont mainStart(mainChain);

    if(hasStraggler)
    {
        size_t idx_straggler = group_count * pair_size;
        It first_straggler = container.begin() + idx_straggler;
        It last_straggler = first_straggler + order;

        pend.push_back(IntCont(first_straggler, last_straggler));
    }

    // B1 is allways smaller than A1
    mainChain.insert(mainChain.begin(), pend.begin(), pend.begin() + 1);
    //pend.erase(pend.begin());

    // generate jacobsthal sequence
    IdxCont jacobsthalOrder = buildJacobsthalUpTo<C>(pend.size());

    // generate insertion order based on jacobsthal sequence
    IdxCont insertOrder = buildInsertionOrderFromJacob<C>(jacobsthalOrder, pend.size());

    // insert each group of pend in mainChain
    for (size_t i = 0; i < insertOrder.size(); i++)
    {
        IntCont group = pend[i];
        int big = group[order - 1]; // biggest element of group

        // group A of pend[i] is in mainOrigin
        // pend[i] is allways smaller than it's A partner
        // the search limit is the position of it's A partner
        PIt limit = std::find(mainChain.begin(), mainChain.end(), mainStart[i]);
        PIt pos = findPositionByBinarySearch<C>(mainChain, limit, order, big);
        mainChain.insert(pos, group);
    }

    IntCont result;
    for(PIt pt = mainChain.begin(); pt != mainChain.end(); pt++)
    {
        result.insert(result.end(), (*pt).begin(), (*pt).end());
    }

    container = result;
}

template < template <class, class> class C >
void pmergeSort(typename Cont<C>::intCont &c)
{
    
    print_numbers("Before: ", c);
    fordJhonsonSortByBig<C>(c, 1);
    print_numbers("After : ", c);
}

// recolher tempo passando como argumento
// uma variavel que guarda o tempo no final do sort