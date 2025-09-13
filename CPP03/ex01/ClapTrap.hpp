/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:19:00 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/13 20:17:38 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_HPP
# define CLAP_HPP

# include <iostream>
# include <string>


class ClapTrap {
    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &copy);
        ~ClapTrap();

        ClapTrap &operator=(const ClapTrap &copy);

        std::string getName() const;
        int		    getHitPoints() const;
		int		    getEnergyPoints() const;
		int		    getAttackDamage() const;
        void	    setName(const std::string &name);
		void	    setHitPoints(int hitPoints);
		void	    setEnergyPoints(int energyPoints);
		void	    setAttackDamage(int attackDamage);

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
        protected:
        std::string _name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
};

#endif