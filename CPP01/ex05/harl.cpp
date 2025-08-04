/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:51:28 by ismailalash       #+#    #+#             */
/*   Updated: 2025/08/04 12:31:06 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

void Harl::debug(void)
{
    std::cout << "--: DEBUG :--\n";
    std::cout << "I love having extra bacon for my \n"
                << "7XL-double-cheese-triple-pickle-special- ketchup burger. \n"
                << "stdI really do!\n";
}

void Harl::info(void)
{
    std::cout << "--: INFO :--\n";
    std::cout << "I cannot believe adding extra bacon costs more money.\n"
                << "You didn't put enough bacon in my burger! If you did,\n" 
                << "I wouldn't be asking for more!\n";
}

void Harl::warning(void)
{
    std::cout << "--: WARNING :--\n";
    std::cout << "I think I deserve to have some extra bacon for free.\n"
                << "I've been coming for years, whereas you started working\n"
                << "here just last month.\n";
}

void Harl::error(void)
{
    std::cout << "--: ERROR :--\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string &level)
{
    void (Harl::*functions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };
    std::string instructions[] = {"DEBUG", "ERROR", "INFO", "WARNING"};
    int i = 0;
    while(i < 4)
    {
        if(instructions[i] == level)
        {
            (this->*functions[i])();
            return;
        }
        i++;
    }
}

