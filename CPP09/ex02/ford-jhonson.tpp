#include "pmergeme.hpp"

template <typename Cont>
Cont buildJacobsthalUpTo(int max)
{
    /*J(0)=0
    J(1)=1
    J(n)=J(n-1) + 2*J(n-2)*/

    Cont jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while(jacob.back() < max)
    {
        jacob.push_back(jacob.back() + 2 * *(jacob.end() - 2));
    }
    return jacob;
}

template <typename Cont>
Cont buildInsertionOrderFromJacob(size_t max)
{
    Cont order;
    Cont inserted(max, false);
    Cont J = buildJacobsthalUpTo<Cont>(max);

    for(size_t k = 2; k <= J.size() - 1; k++)
    {
        size_t start = J[k - 1];
        size_t end = min(J[k], max);

        for(size_t i = end - 1; i >= start; i--)
        {
            if(i >= 0 && i < max && !inserted[i])
            {
                order.push_back;
                inserted[i] = true;
            }
        }
    }

    for(size_t i = 0; i < max; i++)
        if(!inserted[i])
            order.push_back(i);
    
    return order;
}

template <typename PairCont>
typename PairCont::iterator findByIdx(PairCont &result, const size_t idx)
{
    typename PairCont::iterator it = result.begin();
    for(; it != result.end(); it++)
    {
        if(it->idx == idx)
            return it;
    }
    return result.end();
}

struct ComparePairByBig
{
    bool operator()(t_pair const& a, t_pair const& b) const
    {
        if (a.big != b.big) return a.big < b.big;
        return a.small < b.small;
    }
};

template <typename Cont, typename PairCont>
void fordJhonsonSortPairsByBig(PairCont &pairs)
{
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
    for(typename PairCont::iterator it = pairs.begin(); it != pairs.end(); idx++)
    {
        typename PairCont::iterator next = it;
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

    fordJhonsonSortPairsByBig(biggers);

    PairCont result = biggers;

    Cont insertOrder = buildInsertionOrderFromJacob(smallers.size());

    ComparePairByBig cmp;
    for(size_t i = 0; i < insertOrder.size(); i++)
    {
        int idx = insertOrder[i];
        typename PairCont::iterator biggerIt = findByIdx(result, smallers[idx].idx);
        typename PairCont::iterator limit = biggerIt + 1;
        typename PairCont::iterator pos = lower_bound(result.begin(), limit, smallers[idx], cmp);
        result.insert(pos, smallers[idx]);
    }
    pairs = result;
}

template <typename Cont, typename PairCont>
void pmergeSort(Cont &c)
{
    PairCont pairs;
    int straggler = 0;
    bool hasStraggler = false;

    if(c.size() % 2 != 0)
    {
        straggler = c.back();
        hasStraggler = true;
    }

    for(typename Cont::iterator it = c.begin(); it != c.end();)
    {
        typename Cont::iterator next = it;
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
    fordJhonsonSortPairsByBig(pairs);
    print_pairs("After: ", pairs);
}

// como gerir o time - unidade e funcao gettime

//  corrigir compile errors e testar sorting dos biggers em pair