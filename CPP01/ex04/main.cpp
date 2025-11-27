/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/11/27 18:49:47 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Arguments.hpp"
#include "File.hpp"

int main(int argc, char **argv)
{
    Arguments args(argc, argv);
    
    if (!args.validate())
        return 1;
    std::cout << "PASS\n";
    return 0;
}