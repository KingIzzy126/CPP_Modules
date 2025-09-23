/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:45:42 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/19 16:45:42 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const std::string &type) : _type(type)
{
    std::cout << "Animal named constructor called\n";
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
    std::cout << "Animal copy constructor called\n";
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

Animal &Animal::operator=(const Animal &copy)
{
    if (this != &copy)
    {
        _type = copy._type;
    }
    std::cout << "Animal assignment operator called\n";
    return *this;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound\n";
}

std::string Animal::getType() const
{
    return _type;
}