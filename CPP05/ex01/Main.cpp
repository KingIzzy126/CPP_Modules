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
#include "Form.hpp"

int main()
{
    Form rForm("Resupply Base", 60, 15);
    Form mForm("Missile Launch", 25, 5);
    Bureaucrat officer("Lieutenant", 45);
    Bureaucrat soldier("Corporal", 110);

    std::cout << "--- Create Form Test ---\n";
    {
        std::cout << rForm << "\n";
    }
    std::cout << "\n--- Sign Ressupply Base Form Test (Success) ---\n";
    {
        std::cout << officer << "\n";
        std::cout << rForm << "\n";
        officer.signForm(rForm);
        std::cout << rForm << "\n";
    }
    std::cout << "\n--- Sign Missile Launch Form Test (Fail) ---\n";
    {
        std::cout << soldier << "\n";
        std::cout << mForm << "\n";
        soldier.signForm(mForm);
        std::cout << mForm << "\n";
    }
    std::cout << "\n--- Invalid Form Test (Grade Too High/ Low) ---\n";
    {
        try
        {
            Form invalidForm("Invalid High", 0, 50);
        }
        catch(const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << '\n';
        }
         try
        {
            Form invalidForm("Invalid Low", 50, 151);
        }
        catch(const std::exception &e)
        {
            std::cout << "Exception: " << e.what() << '\n';
        }
    }
    return (0);
}