/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:52:17 by mateferr          #+#    #+#             */
/*   Updated: 2026/02/03 14:57:23 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm{

    private:
    const std::string _target;
    RobotomyRequestForm(void);
    
    public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& form);
    ~RobotomyRequestForm(void);
    
    RobotomyRequestForm& operator=(const RobotomyRequestForm& form);
    const std::string& getTarget(void) const;
    void execute(Bureaucrat const & executor) const;
};

#endif