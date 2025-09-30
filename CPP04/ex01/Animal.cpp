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

/* ---------------------------------------------- */
/*          Constructors & operators              */
/* ---------------------------------------------- */

Animal::Animal() : _type("Animal")
{
    std::cout << "Animal -" << _type << "- default constructor called\n";
}

Animal::Animal(const std::string &type) : _type(type)
{
    std::cout << "Animal -" << _type << "- named constructor called\n";
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
    std::cout << "Animal -" << _type << "- copy constructor called\n";
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

Animal::~Animal()
{
    std::cout << "Animal -" << _type << "- destructor called\n";
}

void Animal::makeSound() const
{
    std::cout << "Animal -" << _type << "- made a sound\n";
}

/* ---------------------------------------------- */
/*             Setters and Getters                */
/* ---------------------------------------------- */

void Animal::setType(const std::string &type)
{
    this->_type = type;
}

std::string Animal::getType() const
{
    return _type;
}