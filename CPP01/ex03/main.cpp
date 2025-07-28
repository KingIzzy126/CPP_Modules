/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 20:07:19 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/28 20:22:49 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main() {
    std::cout << "✧──────────✧────────────✧───────────✧──────────✧──────────✧\n";
    {
    Weapon club = Weapon("crude spiked club");
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
    }
    std::cout << "✧──────────✧────────────✧───────────✧──────────✧──────────✧\n";
    {
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    }
    std::cout << "✧──────────✧────────────✧───────────✧──────────✧──────────✧\n";
    return 0;
}