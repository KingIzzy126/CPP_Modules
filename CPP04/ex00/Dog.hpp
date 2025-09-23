/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:49:58 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/19 16:49:58 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(std::string type);
        Dog(const Dog &copy);
        virtual ~Dog();
        Dog &operator=(const Dog &copy);

        virtual void makeSound() const;
};

#endif