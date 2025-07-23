/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:09:55 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/23 19:15:01 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* Zombie1 = zombieHorde(7, "Zombie1");
    Zombie1[0].announce();
    Zombie1[1].announce();
    Zombie1[2].announce();
    Zombie1[3].announce();
    Zombie1[4].announce();
    Zombie1[5].announce();
    Zombie1[6].announce();
    delete[] Zombie1;
}