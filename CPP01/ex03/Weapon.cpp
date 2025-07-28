/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:30:43 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/27 20:10:58 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string Weapon) {
    type = Weapon;
}

Weapon::~Weapon() {
    std::cout << type << " has been destroyed :(\n";
}

std::string Weapon::getType() {
    return type;
}

void Weapon::setType(std::string newType) {
    type = newType;
}