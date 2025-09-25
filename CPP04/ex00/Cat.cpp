/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:45:10 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/19 16:45:10 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* ---------------------------------------------- */
/*          Constructors & operators              */
/* ---------------------------------------------- */

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat default constructor called\n";
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat named constructor called\n";
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called\n";
}

Cat &Cat::operator=(const Cat &copy)
{
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    std::cout << "Cat assignment operator called\n";
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "Meow meow >:)\n";
}