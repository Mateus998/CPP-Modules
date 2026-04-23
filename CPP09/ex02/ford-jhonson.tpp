#include "pmergeme.hpp"

template < template <class, class> class C >
struct Cont
{
    typedef C<size_t, std::allocator<size_t> > size_tCont;
    typedef C<int,    std::allocator<int>    > intCont;
    typedef C<bool,   std::allocator<bool>   > boolCont;
    typedef C<t_pair, std::allocator<t_pair> > pairCont;
};

// template < template <class, class> class C >
// typename Cont<C>::size_tCont buildInsertionOrderFromJacob(size_t max)
// {
//     typedef typename Cont<C>::size_tCont Size_tCont;
//     typedef typename Cont<C>::boolCont BoolCont;

//     Size_tCont order;
//     BoolCont inserted(max, false);
//     Size_tCont J = buildJacobsthalUpTo<C>(max);

//     for(size_t k = 2; k <= J.size() - 1; k++)
//     {
//         size_t start = J[k - 1];
//         size_t end = std::min(static_cast<size_t>(J[k]), max);

//         for (size_t i = end; i-- > start; )
//         {
//             if (i < max && !inserted[i])
//             {
//                 order.push_back(i);
//                 inserted[i] = true;
//             }
//         }


//     }

//     for(size_t i = 0; i < max; i++)
//         if(!inserted[i])
//             order.push_back(i);
    
//     return order;
// }

// template < template <class, class> class C >
// typename Cont<C>::pairCont::iterator findByIdx(typename Cont<C>::pairCont &result, const size_t idx)
// {
//     typedef typename Cont<C>::pairCont::iterator It;

//     It it = result.begin();
//     for(; it != result.end(); it++)
//     {
//         if(it->idx == idx)
//             return it;
//     }
//     return result.end();
// }

// template < template <class, class> class C >
// typename Cont<C>::pairCont::iterator findPositionByBinarySearchByBig(
//     typename Cont<C>::pairCont &result,
//     t_pair &pendVal)
// {
//     typedef typename Cont<C>::pairCont::iterator It;

//     It biggerIt = findByIdx<C>(result, pendVal.idx);
//     It limit = biggerIt != result.end() ? biggerIt + 1 : biggerIt;

//     It left = result.begin();
//     It right = limit;

//     while(left != right)
//     {
//         It mid = left + (right - left) / 2;
//         if (mid->big < pendVal.big)
//             left = mid + 1;
//         else
//             right = mid;
//     }
//     return left;
// }

// template < template <class, class> class C >
// void insertSmallersPairsInBiggers(typename Cont<C>::pairCont &result, typename Cont<C>::pairCont &toInsert)
// {
//     typedef typename Cont<C>::size_tCont Size_tCont;
//     typedef typename Cont<C>::pairCont::iterator It;

//     Size_tCont insertOrder = buildInsertionOrderFromJacob<C>(toInsert.size());

//     for(size_t i = 0; i < insertOrder.size(); i++)
//     {
//         int idx = insertOrder[i];
//         It pos = findPositionByBinarySearchByBig<C>(result, toInsert[idx]);
//         result.insert(pos, toInsert[idx]);
//     }
// }

// template < template <class, class> class C >
// void insertStragglerPair(typename Cont<C>::pairCont &result, t_pair &straggler)
// {
//     typedef typename Cont<C>::pairCont::iterator It;

//     It pos = findPositionByBinarySearchByBig<C>(result, straggler);
//     result.insert(pos, straggler);
// }

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
    jacob.pop_fornt();
    jacob.pop_fornt();
    jacob.push_front(0);
    return jacob;
}

template < template <class, class> class C >
void fordJhonsonSortByBig(
    typename Cont<C>::intCont &container,
    size_t order)
{
    typedef typename Cont<C>::intCont IntCont;
    typedef typename Cont<C>::size_tCont IdxCont;
    typedef typename IntCont::iterator It;

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
            It lastA = firstB - 1;
            // swap values of group A and B of a pair
            std::swap_ranges(firstA, lastA, firstB);
        }
    }

    // go to next level of pairs
    fordJhonsonSortByBig<C>(container, order * 2);

    // creation of main and pend
    IntCont main; // container of group A of pairs
    IntCont pend; // container of group B of pairs

    for (size_t i = 0; i < group_count; i++)
    {
        size_t idx_a = i * pair_size; //begin of group A (biggers) inside a pair
        size_t idx_b = idx_a + order; //begin of group B (smallers) inside the same pair

        It firstA = container.begin() + idx_a;
        It lastA = firstA + order - 1;
        It firstB = container.begin() + idx_b;
        It lastB = firstB + order - 1;

        main.insert(main.end(), firstA, lastA);
        pend.insert(pend.end(), firstB, lastB);
    }

    if(hasStraggler)
    {
        size_t idx_straggler = group_count * pair_size;
        It first_straggler = container.begin() + idx_straggler;
        It last_straggler = first_straggler + order - 1;

        pend.insert(pend.end(), first_straggler, last_straggler);
    }

    // B1 is allways smaller than A1
    main.insert(main.begin(), pend.begin(), pend.begin() + order - 1);
    pend.erase(pend.begin(), pend.begin() + order - 1);

    // generate jacobsthal order
    IdxCont jacobsthal_order = buildJacobsthalUpTo(pend.size());
    // generate insertion order based on jacobsthal order

    // supostamente pend e main são containers de grupos
    // adicionar container de container à estrutura
}

template < template <class, class> class C >
void pmergeSort(typename Cont<C>::intCont &c)
{
    
    print_numbers("Before: ", c);
    fordJhonsonSortByBig<C>(c, 1);
    print_numbers("After : ", c);
}

// recolher tempo passando como argumento
// uma variavel que guarda o tempo no final do sorting