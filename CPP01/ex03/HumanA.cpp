/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:52:53 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/28 20:21:25 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string str, Weapon &weapon): weapon(weapon) {
    this->name = str;
    std::cout << "HumanA " << this->name << " created with weapon " 
              << this->weapon.getType() << ".\n";
}

HumanA::~HumanA() {
    std::cout << "HumanA " << this->name << " destroyed.\n";
}

void HumanA::attack() {
    std::cout << "HumanA " << this->name << " attacks with "
              << this->weapon.getType() << ".\n";
}