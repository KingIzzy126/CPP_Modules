/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 21:35:00 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/22 21:35:00 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* ---------------------------------------------- */
/*          Constructors & operators              */
/* ---------------------------------------------- */

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal -" << _type << "- default constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
    std::cout << "WrongAnimal -" << _type << "- named constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type)
{
    std::cout << "WrongAnimal -" << _type << "- copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    std::cout << "WrongAnimal assignment operator called\n";
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal -" << _type << "- destructor called\n";
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal -" << _type << "- made a sound\n";
}

/* ---------------------------------------------- */
/*             Setters and Getters                */
/* ---------------------------------------------- */

void WrongAnimal::setType(const std::string &type)
{
    _type = type;
}

std::string WrongAnimal::getType() const
{
    return _type;
}