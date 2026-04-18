/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/04/18 17:28:09 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

    print_numbers("Before: ", vec);
    
    return 0;
}
