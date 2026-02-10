/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/10 17:44:45 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <vector>
#include <climits>

void swapElem(std::vector<int>& vec, int idx1, int idx2){
    int tmp = vec[idx1];
    vec[idx1] = vec[idx2];
    vec[idx2] = tmp;
}

std::vector<int> fordJohnson(std::vector<int>& input){
    if (input.size() == 1 || input.size() == 0)
        return input;
    if (input.size() == 2){
        if(input[0] > input[1])
            swapElem(input, 0, 1);
        return input;
    }
    std::vector<int, int> pars;
    for(std::vector<int>::iterator it = input.begin(); it != input.end(); it += 2){
        if(it + 1 != input.end()){
            if(*it > *(it + 1)){
                //....
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if(argc < 3)
        return std::cout << "Error" << std::endl, 1;
    try{
        //.....parsing.....
        std::vector<int> input;
        long n;
        std::stringstream ss;
        for(int i = 1; i < argc; i++){
            std::string arg(argv[i]);
            for(size_t j = 0; j < arg.size(); j++){
                if (!isdigit(arg[j]))
                    throw std::runtime_error("Invalid input value");
            }
            ss << arg;
            ss >> n;
            if(ss.fail() && !ss.eof())
                throw std::runtime_error("Invalid number");
            ss.clear();
            if (n > INT_MAX)
                throw std::runtime_error("overflow");
            input.push_back(n);
        }

        
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}
