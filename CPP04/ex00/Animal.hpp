/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:45:32 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/19 16:45:32 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string	_type;

    public:
        Animal();
        Animal(const std::string &type);
        Animal(const Animal &copy);
        virtual ~Animal();

        Animal	&operator=(const Animal &copy);

        virtual void	makeSound() const;
        std::string		getType() const;
};

#endif