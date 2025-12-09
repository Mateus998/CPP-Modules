/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/09 14:41:36 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Arguments.hpp"
#include "File.hpp"
#include "Replacer.hpp"

int main(int argc, char **argv)
{
    Arguments args(argc, argv);
    if (!args.validate())
        return 1;
    
    File infile(args.getFileName());
    File outfile(args.getFileName() + ".replace");
    if (!infile.openRead() || !outfile.openWrite())
        return 1;

    Replacer replace(args.getS1(), args.getS2());
    replace.processFiles(infile.getStream(), outfile.getStream());
    return 0;
}
