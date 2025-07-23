/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:21:29 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/23 19:18:45 by ialashqa         ###   ########.fr       */
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
        ~Zombie();
        Zombie(std::string inputName);

};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif