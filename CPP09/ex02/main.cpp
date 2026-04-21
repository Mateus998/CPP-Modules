#include "pmergeme.hpp"

int main(int argc, char* argv[]) {
    std::vector<int> vec;
    std::deque<int> dec;
    
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

    dec.insert(dec.begin(), vec.begin(), vec.end());
    
    // print_numbers<std::vector<int>>("Before: ", vec);
    pmergeSort< std::vector >(vec);
    // pmergeSort<std::deque<int>, std::deque<t_pair>>(dec);
    // print_numbers<std::vector<int>>("After: ", vec);
    
    return 0;
}