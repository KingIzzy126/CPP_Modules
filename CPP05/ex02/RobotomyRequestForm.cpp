/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:59:11 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/07 17:59:11 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor was created\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm parameterized constructor was created\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
    : AForm(copy), _target(copy._target)
{
    std::cout << "RobotomyRequestForm copy constructor was created\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
    std::cout << "RobotomyRequestForm assignment operator was created\n";
    if (this != &copy)
    {
        AForm::operator=(copy);
        _target = copy._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor was created\n";
}

const std::string &RobotomyRequestForm::getTarget() const
{
    return (_target);
}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "* DRILLING NOISES * BZZZZZZZZ BOOOOOOM BOOM KABOOM....\n";
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully!\n";
    else
        std::cout << "Robotomy failed on " << _target << "!\n";
}