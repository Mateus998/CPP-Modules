#include "pmergeme.hpp"

int main(int argc, char* argv[]) {
    std::vector<int> vec;
    std::deque<int> deq;
    
    if(argc < 3)
        return std::cerr << "Error" << std::endl, 1;
    try{
        for(int i = 1; i < argc; i++){
            parse(argv[i], vec);
        }
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
        return 1;
    }

    deq.insert(deq.begin(), vec.begin(), vec.end());
    
    long vecTime;
    long deqTime;

    print_numbers< std::vector<int> >("Before: ", vec);
    pmergeSort< std::deque >(deq, &deqTime);
    pmergeSort< std::vector >(vec, &vecTime);
    print_numbers< std::vector<int> >("After: ", vec);
    
    checkSorting(vec, deq);

    std::cout << "Time to process a range of "
    << argc - 1 << " elements with std::vector : "
    << vecTime << " us" << std::endl;

    std::cout << "Time to process a range of "
    << argc - 1 << " elements with std::deque : "
    << deqTime << " us" << std::endl;
    
    return 0;
}