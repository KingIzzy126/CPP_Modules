/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:51:28 by ismailalash       #+#    #+#             */
/*   Updated: 2025/08/04 13:50:37 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

void Harl::debug(void)
{
    std::cout << "--: DEBUG :--\n";
    std::cout << "I love having extra bacon for my \n"
                << "7XL-double-cheese-triple-pickle-special- ketchup burger. \n"
                << "I really do!\n \n";
}

void Harl::info(void)
{
    std::cout << "--: INFO :--\n";
    std::cout << "I cannot believe adding extra bacon costs more money.\n"
                << "You didn't put enough bacon in my burger! If you did,\n" 
                << "I wouldn't be asking for more!\n\n";
}

void Harl::warning(void)
{
    std::cout << "--: WARNING :--\n";
    std::cout << "I think I deserve to have some extra bacon for free.\n"
                << "I've been coming for years, whereas you started working\n"
                << "here just last month.\n\n";
}

void Harl::error(void)
{
    std::cout << "--: ERROR :--\n";
    std::cout << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::filter(const std::string &level)
{
    int i = -1;
    if (level == "DEBUG")
        i = 0;
    else if (level == "INFO")
        i = 1;
    else if (level == "WARNING")
        i = 2;
    else if (level == "ERROR")
        i = 3;

    switch (i) {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << "Invalid level: " << level << "\n";
            std::cout << "Available levels: DEBUG, INFO, WARNING, ERROR\n";
            break;
    }
}

