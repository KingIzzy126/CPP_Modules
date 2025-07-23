/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:09:46 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/23 19:05:08 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    if (N < 0)
        return NULL;
    Zombie* horde = new Zombie[N];
    int i = 0;
    while(i < N) {
        horde[i].setName(name);
        i++;
    }
    return horde;
}