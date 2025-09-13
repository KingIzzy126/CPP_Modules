/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:28:48 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/13 18:21:45 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* ---------------------------------------------- */
/*          Constructors & operators              */
/* ---------------------------------------------- */

ClapTrap::ClapTrap() 
{
    std::cout << "< ClapTrap Default constructor was created >\n";
    _name = "";
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) 
{
    _name = name;
    hitPoints = 10;
    energyPoints = 10;
    attackDamage = 0;
    std::cout << " < ClapTrap " << _name << " was created >\n";
    std::cout << "✧──────────✧────────────✧───────────✧\n";
    std::cout << "| Hit Points : " << hitPoints << "                   |\n";
    std::cout << "| Energy Points : " << energyPoints << "                |\n";
    std::cout << "| Attack Damage : " << attackDamage << "                 |\n";
    std::cout << "✧──────────✧────────────✧───────────✧\n";
    
}

ClapTrap::ClapTrap(const ClapTrap &copy) 
{
    std::cout << "ClapTrap Copy constructor was created\n";
    *this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) 
{
    std::cout << "ClapTrap assignment operator was called\n";
    if (this != &copy) {
        _name = copy._name;
        hitPoints = copy.hitPoints;
        energyPoints = copy.energyPoints;
        attackDamage = copy.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << _name << " destructor called\n";
}

/* ---------------------------------------------- */
/*               Member Functions                 */
/* ---------------------------------------------- */

void ClapTrap::attack(const std::string &target) 
{
    if (hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is dead.. cannot attack!\n";
    }
    else if (energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left to attack!\n";
    }
    else {
        std::cout << "ClapTrap " << _name << " attacks " << target << ", with " << attackDamage << " points of damage!\n";
        energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount) 
{
    std::cout << _name << " took " << amount << " of damage!\n";
    hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) 
{
    if (hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is dead.. cannot repair!\n";
    }
    else if (energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " has no energy points left to repair!\n";
    }
    else {
        std::cout << _name << " is repaired by " << amount << " hp!\n";
        hitPoints += amount;
        energyPoints--;
    }
}

/* ---------------------------------------------- */
/*             Setters and Getters                */
/* ---------------------------------------------- */

int	ClapTrap::getHitPoints() const 
{
	return hitPoints;
}

int	ClapTrap::getEnergyPoints() const 
{
	return energyPoints;
}

int	ClapTrap::getAttackDamage() const 
{
	return attackDamage;
}

void	ClapTrap::setHitPoints(int HitPoints) 
{
	hitPoints = HitPoints;
}

void	ClapTrap::setEnergyPoints(int EnergyPoints) 
{
	energyPoints = EnergyPoints;
}

void	ClapTrap::setAttackDamage(int AttackDamage) 
{
	attackDamage = AttackDamage;
}