/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:53:03 by ialashqa          #+#    #+#             */
/*   Updated: 2025/08/05 15:58:01 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon* weapon;
    public:
    HumanB(std::string name);
    void setWeapon(Weapon& weapon);
    void attack();
    ~HumanB();
};

#endif