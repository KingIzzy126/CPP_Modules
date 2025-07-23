/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:09:48 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/23 19:18:33 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        Zombie();
        void announce(void);
        void setName(std::string inputName);
        ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif