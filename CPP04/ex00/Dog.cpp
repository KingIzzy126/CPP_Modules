/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:50:03 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/19 16:50:03 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called\n";
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog named constructor called\n";
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called\n";
}

Dog &Dog::operator=(const Dog &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    std::cout << "Dog assignment operator called\n";
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof\n";
}