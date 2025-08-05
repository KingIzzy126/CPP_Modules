/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:25:04 by ialashqa          #+#    #+#             */
/*   Updated: 2025/08/05 15:57:47 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->weapon = NULL;
    this->name = name;
    std::cout << "HumanB " << this->name << " created.\n"; 
}

void HumanB::setWeapon (Weapon &weapon) {
    this->weapon = &weapon;
    std::cout << "HumanB" << this->name << " set weapon to " << weapon.getType() 
                << ".\n";
}

void HumanB::attack() {
    if (this->weapon) {
        std::cout << "HumanB " << this->name << " atacks with "
                    << this->weapon->getType() << ".\n";
    }
    else {
        std::cout << "HumanB " << this->name << " has no weapon" 
                    << ".\n";
    }
}

HumanB::~HumanB() {
    std::cout << "HumanB " << this->name << " destroyed.\n";
}