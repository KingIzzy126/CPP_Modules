/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:37:27 by ismailalash       #+#    #+#             */
/*   Updated: 2025/09/13 18:26:00 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap robot1;                   // 1. Default Regular Constructor
    ClapTrap robocop("Robocop");       // 2. Named Constructor1
    ClapTrap terminator("Terminator"); // 3. Named Constructor2
    ClapTrap robocop_copy(robocop);    // 4. Copy Constructor

    std::cout << "\n=== BATTLE TIME! ===\n";
    robocop.setAttackDamage(3);
    robocop.attack("Terminator");
    terminator.takeDamage(robocop.getAttackDamage());
    terminator.beRepaired(2);

    std::cout << "\n=== FINAL STATS ===\n";
    std::cout << "✧─────────── ROBOCOP ───────────✧\n";
    std::cout << "| Hit Points: " << robocop.getHitPoints() << "                  |\n";
    std::cout << "| Energy Points: " << robocop.getEnergyPoints() << "               |\n";
    std::cout << "| Attack Damage: " << robocop.getAttackDamage() << "               |\n";
    std::cout << "✧──────────────────────────────✧\n";
    
    std::cout << "\n✧────────── TERMINATOR ─────────✧\n";
    std::cout << "| Hit Points: " << terminator.getHitPoints() << "                  |\n";
    std::cout << "| Energy Points: " << terminator.getEnergyPoints() << "               |\n";
    std::cout << "| Attack Damage: " << terminator.getAttackDamage() << "               |\n";
    std::cout << "✧──────────────────────────────✧\n";
    
    std::cout << "\n✧─────────── COPY ──────────────✧\n";
    std::cout << "| Hit Points: " << robocop_copy.getHitPoints() << "                  |\n";
    std::cout << "| Energy Points: " << robocop_copy.getEnergyPoints() << "               |\n";
    std::cout << "| Attack Damage: " << robocop_copy.getAttackDamage() << "               |\n";
    std::cout << "✧──────────────────────────────✧\n";

    return (0);
}