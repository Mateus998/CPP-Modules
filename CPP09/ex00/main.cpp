/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/06 18:58:39 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char* argv[]) {
    if(argc != 2)
        return std::cout << "Error: 1 arg only" << std::endl, 1;
    try{
        BitcoinExchange::loadDatabaseFile();
        std::string input(argv[1]);
        BitcoinExchange::bitcoinExchange(input);
    }
    catch(std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
