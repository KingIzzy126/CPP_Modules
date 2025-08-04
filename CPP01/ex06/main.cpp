/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 18:51:32 by ismailalash       #+#    #+#             */
/*   Updated: 2025/08/04 13:51:11 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    if (ac != 2)
    {
        std::cout << "Usage ./harlFilter <log level>\n"
                    << "Levels: {DEBUG, INFO, WARNING, ERROR}\n";
        return (1);
    }
    harl.filter(av[1]);
    return 0;
}