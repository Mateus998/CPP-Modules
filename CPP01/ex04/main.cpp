/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 17:31:43 by mateferr          #+#    #+#             */
/*   Updated: 2025/12/10 11:27:39 by mateferr         ###   ########.fr       */
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
    
    File files(args.getFileName());
    if (!files.openStreams())
        return 1;

    Replacer replace(args.getS1(), args.getS2());
    if(!replace.processFiles(files.getIstream(), files.getOstream()))
        return 1;
    return 0;
}
