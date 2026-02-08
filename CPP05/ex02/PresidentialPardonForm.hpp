/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:06:35 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 15:07:44 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{

    private:
    const std::string _target;
    PresidentialPardonForm(void);
    
    public:
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm(const PresidentialPardonForm& form);
    ~PresidentialPardonForm(void);
    
    PresidentialPardonForm& operator=(const PresidentialPardonForm& form);
    const std::string& getTarget(void) const;
    void execute(Bureaucrat const & executor) const;
};

#endif