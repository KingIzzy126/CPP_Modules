/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 19:37:26 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/07 19:37:26 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/* ---------------------------------------------- */
/*          Constructors & Destructor             */
/* ---------------------------------------------- */

Intern::Intern()
{
    std::cout << "Intern default constructor was created\n";
}

Intern::Intern(const Intern &copy)
{
    std::cout << "Intern copy constructor was created\n";
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy)
{
    std::cout << "Intern assignment operator was created\n";
    if(this == &copy)
        return *this;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor was destroyed\n";
}

/* ---------------------------------------------- */
/*                    Functions                   */
/* ---------------------------------------------- */

static AForm *createShrubbery(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}

static AForm *createRobotomy(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *createPresidential(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    AForm *(*formCreator[])(const std::string &) = {&createShrubbery, &createRobotomy,  &createPresidential};
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    int i = 0;
    while (i < 3)
    {
        if (formNames[i] == formName)
        {
            AForm *form = formCreator[i](target);
            std::cout << "Intern creates " << formName << " form\n";   
            return (form);
        }
        i++;
    }
    std::cout << "Intern couldn't find the form: " << formName << "\n";
    return (NULL);
}