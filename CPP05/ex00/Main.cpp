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

int main()
{
    Bureaucrat a;
    Bureaucrat b("King", 1);
    Bureaucrat c("Loki", 100);
    Bureaucrat d("Thor", 50);

    std::cout << "--- Default constructor test ---\n";
    {
        std::cout << a << "\n";
    }
    std::cout << "\n--- Parameterized constructor test ---\n";
    {
        std::cout << b << "\n";
    }
    std::cout << "\n--- Copy constructor test ---\n";
    {
        Bureaucrat e(d);
        std::cout << d << "\n";
        std::cout << e << "\n";
    }
    std::cout << "\n--- Assignment operator test ---\n";
    {
        Bureaucrat f;
        f = d;
        std::cout << d << "\n";
        std::cout << f << "\n";
    }

    // TESTS:

    {
        std::cout << "\n--- Incrementing Loki test ---\n";
        std::cout << "Before: " << c << "\n";
        c.incrementGrade();
        std::cout << "After: " << c << "\n";
    }
    {
        std::cout << "\n--- Decrementing Thor test ---\n";
        std::cout << "Before: " << d << "\n";
        d.decrementGrade();
        std::cout << "After: " << d << "\n";
    }
    {
        std::cout << "\n--- Grade too high exception test ---\n";
        try
        {
            std::cout << "\n--- Incrementing King test ---\n";
            std::cout << "Before: " << b << "\n";
            b.incrementGrade();
            std::cout << "After: " << b << "\n";
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << "\n";
        }
    }
    // {
    //         std::cout << "\n--- Incrementing King test no try and catch ---\n";
    //         std::cout << "Before: " << b << "\n";
    //         b.incrementGrade();
    //         std::cout << "After: " << b << "\n";
    // }
    return (0);
}