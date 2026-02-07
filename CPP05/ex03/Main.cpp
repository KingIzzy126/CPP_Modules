/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 20:35:27 by ialashqa          #+#    #+#             */
/*   Updated: 2026/02/04 20:35:27 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));

    Intern intern;
    Bureaucrat boss("Boss", 1);
    AForm *form;
    
    std::cout << "--- Intern creates Shrubbery Creation Form ---\n";
    {
        form = intern.makeForm("shrubbery creation", "home");
        if (form)
        {
            std::cout << *form << "\n";
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    std::cout << "\n--- Intern creates Robotomy Request Form ---\n";
    {
        form = intern.makeForm("robotomy request", "construction");
        if (form)
        {
            std::cout << *form << "\n";
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    std::cout << "\n--- Intern creates Presidential Pardon Form ---\n";
    {
        form = intern.makeForm("presidential pardon", "low rank employee");
        if (form)
        {
            std::cout << *form << "\n";
            boss.signForm(*form);
            boss.executeForm(*form);
            delete form;
        }
    }
    std::cout << "\n--- Intern tries to create unknown form ---\n";
    {
        form = intern.makeForm("unknown form", "target");
        if (form)
            delete form;
    }
    return (0);
}


