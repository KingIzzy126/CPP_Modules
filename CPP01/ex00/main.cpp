/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:20:00 by ialashqa          #+#    #+#             */
/*   Updated: 2025/08/03 16:36:12 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie* zombie1 = newZombie("Izzy");
    zombie1->announce();
    randomChump("piercey");
    delete zombie1;
}