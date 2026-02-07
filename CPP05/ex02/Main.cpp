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


int main()
{
    std::srand(std::time(0)); 
    Bureaucrat president("Presidenteh", 1);
    Bureaucrat manager("Manager", 45);
    Bureaucrat employee("Employee", 140);

    std::cout << "--- Shrubbery Creation Form Test ---\n";
    {
        ShrubberyCreationForm shrub("home");
        std::cout << shrub << "\n";

        employee.signForm(shrub);
        employee.executeForm(shrub);
        std::cout << shrub << "\n";
    }
    std::cout << "\n---Robotomy Request Form Test ---\n";
    {
        RobotomyRequestForm robot("construction");
        std::cout << robot << "\n";
        
        manager.signForm(robot);
        manager.executeForm(robot);
        std::cout << robot << "\n";
    }
    std::cout << "\n--- Presidential Pardon Form Test ---\n";
    {
        PresidentialPardonForm pardon("intern");
        std::cout << pardon << "\n";

        president.signForm(pardon);
        president.executeForm(pardon);
        std::cout << pardon << "\n";
    }
    std::cout << "\n--- execution without signing ---" << std::endl;
    {
        ShrubberyCreationForm shrub("garden");
        employee.executeForm(shrub);  // Should fail - not signed
    }

    std::cout << "\n--- grade too low to execute ---" << std::endl;
    {
        PresidentialPardonForm pardon("intern");
        president.signForm(pardon);
        manager.executeForm(pardon);  // Should fail - grade too low
    }
    return (0);
}


