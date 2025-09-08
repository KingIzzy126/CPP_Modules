/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:28:48 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/08 16:59:05 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(std::string name) : _name(name) {
    std::cout << "ClapTrap mister" << _name << "was created\n";
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
    std::cout << "ClapTrap copy constructor called\n";
    *this = copy;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
    std::cout << "ClapTrap assignment operator called\n";
    if (this != &copy) {
        _name = copy._name;
        hitPoints = copy.hitPoints;
        energyPoints = copy.energyPoints;
        attackDamage = copy.attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string &target) {
    if (energyPoints >= 1)
    {
        std::cout << "Claptrap " << _name << " attacks " << target << ", with " << attackDamage << " points of damage!\n";
        energyPoints--;
    }
    else if (energyPoints <= 0)
        std::cout << "Claptrap " << _name << " has no energy points left to attack!\n";
    else
        std::cout << "Claptrap " << _name << " has no hit points left to attack!\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
    
}