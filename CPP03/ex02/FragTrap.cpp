/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 23:04:00 by ismailalash       #+#    #+#             */
/*   Updated: 2026/02/09 13:06:47 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "--Default FragTrap constructor has joined the arena--\n";
}

FragTrap::~FragTrap() {
    std::cout << "--BIG BOY FragTrap " << getName() << " left the arena--\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "--BIG BOY FragTrap " << name << " has joined the arena--\n";
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy) {
    std::cout << "--BIG BOY FragTrap copy constructor called--\n";
}

FragTrap &FragTrap::operator=(const FragTrap &copy) {
    std::cout << "--BIG BOY FragTrap assignment operator called--\n";
    if (this != &copy) {
        ClapTrap::operator=(copy); // Call parent assignment operator
    }
    return *this;
}

void FragTrap::highFivesGuys(void) {
    std::cout << "--BIG BOY FragTrap high fives guys!--" << std::endl;
}
