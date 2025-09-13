/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:37:27 by ismailalash       #+#    #+#             */
/*   Updated: 2025/09/13 20:43:09 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== CREATING ROBOTS ===\n";
    ClapTrap robocop("Robocop");       // 1. ClapTrap Named Constructor1
    ClapTrap terminator("Terminator"); // 2. ClapTrap Named Constructor2
    // ScavTrap robot1;                   // 1a. ScavTrap Regular Constructor
    ScavTrap t3000("T-3000");          // 2a. ScavTrap Named Constructor

    // std::cout << "\n=== SCAVTRAP TESTS ===\n";
    // ScavTrap scav_copy(t3000);         // Copy constructor
    // ScavTrap scav_assignment("Assignment Test");
    // scav_assignment = t3000;           // Assignment operator

    std::cout << "\n=== SCAVTRAP SPECIAL ABILITY ===\n";
    t3000.guardGate();
    
    std::cout << "\n=== BATTLE TIME! ===\n";
    
    // T-3000 attacks Terminator
    std::cout << "\n--- T-3000 Attacks Terminator ---\n";
    t3000.attack("Terminator");
    if (t3000.getHitPoints() > 0) {    // Only apply damage if attacker is alive
        terminator.takeDamage(t3000.getAttackDamage());
    }

    // Robocop attacks T-3000
    std::cout << "\n--- Robocop Attacks T-3000 ---\n";
    robocop.setAttackDamage(15);
    robocop.attack("T-3000");
    if (robocop.getHitPoints() > 0) {      // Only apply damage if attacker is alive
        t3000.takeDamage(robocop.getAttackDamage());
    }

    // Terminator attacks T-3000
    std::cout << "\n--- Terminator Attacks T-3000 ---\n";
    terminator.setAttackDamage(10);
    terminator.attack("T-3000");
    if (terminator.getHitPoints() > 0) {    // Only apply damage if attacker is alive
        t3000.takeDamage(terminator.getAttackDamage());
    }

    // T-3000 repairs itself
    std::cout << "\n--- T-3000 Repairs ---\n";
    t3000.beRepaired(25);

    std::cout << "\n=== FINAL STATS ===\n";
    std::cout << "✧─────────── ROBOCOP ───────────✧\n";
    std::cout << "| Hit Points: " << robocop.getHitPoints() << "                |\n";
    std::cout << "| Energy Points: " << robocop.getEnergyPoints() << "              |\n";
    std::cout << "| Attack Damage: " << robocop.getAttackDamage() << "             |\n";
    std::cout << "✧───────────────────────────────✧\n";
    
    std::cout << "\n✧────────── TERMINATOR ─────────✧\n";
    std::cout << "| Hit Points: " << terminator.getHitPoints() << "                 |\n";
    std::cout << "| Energy Points: " << terminator.getEnergyPoints() << "             |\n";
    std::cout << "| Attack Damage: " << terminator.getAttackDamage() << "             |\n";
    std::cout << "✧───────────────────────────────✧\n";
    
    std::cout << "\n✧──────────── T-3000 ───────────✧\n";
    std::cout << "| Hit Points: " << t3000.getHitPoints() << "               |\n";
    std::cout << "| Energy Points: " << t3000.getEnergyPoints() << "             |\n";
    std::cout << "| Attack Damage: " << t3000.getAttackDamage() << "             |\n";
    std::cout << "✧───────────────────────────────✧\n";

    // std::cout << "\n✧───────── SCAV COPY ───────────✧\n";
    // std::cout << "| Hit Points: " << scav_copy.getHitPoints() << "               |\n";
    // std::cout << "| Energy Points: " << scav_copy.getEnergyPoints() << "             |\n";
    // std::cout << "| Attack Damage: " << scav_copy.getAttackDamage() << "             |\n";
    // std::cout << "✧───────────────────────────────✧\n";

    // std::cout << "\n✧─────── SCAV ASSIGNMENT ──────✧\n";
    // std::cout << "| Hit Points: " << scav_assignment.getHitPoints() << "              |\n";
    // std::cout << "| Energy Points: " << scav_assignment.getEnergyPoints() << "            |\n";
    // std::cout << "| Attack Damage: " << scav_assignment.getAttackDamage() << "            |\n";
    // std::cout << "✧──────────────────────────────✧\n";

    std::cout << "\n=== DESTRUCTION ORDER ===\n";

    return (0);
}