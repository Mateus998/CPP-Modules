/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 12:00:21 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 14:44:01 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{

    private:
    const std::string _target;
    ShrubberyCreationForm(void);
    
    public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& form);
    ~ShrubberyCreationForm(void);
    
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);
    const std::string& getTarget(void) const;
    void execute(Bureaucrat const & executor) const;
};

#endif