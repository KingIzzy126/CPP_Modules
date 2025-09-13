/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 18:41:56 by ismailalash       #+#    #+#             */
/*   Updated: 2025/09/13 20:11:43 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "< ScavTrap Default constructor was created >\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << " < A ScavTrap " << name << " appeared with: >\n";
    std::cout << "✧──────────✧────────────✧───────────✧\n";
    std::cout << "| Hit Points : " << hitPoints << "                  |\n";
    std::cout << "| Energy Points : " << energyPoints << "                |\n";
    std::cout << "| Attack Damage : " << attackDamage << "                |\n";
    std::cout << "✧──────────✧────────────✧───────────✧\n";
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
    std::cout << "< ScavTrap copy constructor called >\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    std::cout << "< ScavTrap assignment operator called >\n";
    if (this != &copy)
    {
        ClapTrap::operator=(copy);  // Call parent assignment operator
    }
    return *this;
}


ScavTrap::~ScavTrap()
{
    std::cout << " < ScavTrap " << getName() << " was destroyed >\n";
}

void ScavTrap::attack(const std::string &target)
{
    if (hitPoints <= 0) {
        std::cout << "ScavTrap " << _name << " is dead.. cannot attack!\n";
    }
    else if (energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " has no energy points left to attack!\n";
    }
    else {
        std::cout << "ScavTrap " << _name << " SLAMS " << target << ", causing major damage of " << attackDamage << "!\n";
        energyPoints--;
    }
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!\n";
}