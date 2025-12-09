/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 17:10:26 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 15:23:53 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <cctype>
#include <iostream>

int main(int argc, char *argv[])
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; ++i)
    {
        std::string s = argv[i];
        if(s.empty())
            continue;
        for (std::string::iterator j = s.begin(); j != s.end(); j++)
        {
            unsigned char c = static_cast<unsigned char>(*j);
            *j = static_cast<char>(std::toupper(c));
        }
        std::cout << s;
        if (i < argc - 1)
            std::cout << ' ';
    }
    std::cout << '\n';
    return 0;
}
