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
    brain = new Brain();
    if(!brain)
    {
        std::cout << "Failed to allocate memory for Brain\n";
        exit(1);
    }
}

Cat::Cat(std::string type) : Animal(type)
{
    std::cout << "Cat named constructor called\n";
    brain = new Brain();
    if(!brain)
    {
        std::cout << "Failed to allocate memory for Brain\n";
        exit(1);
    }
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called\n";
    brain = new Brain(*copy.brain); // Deep copy of Brain
    if(!brain)
    {
        std::cout << "Failed to allocate memory for Brain\n";
        exit(1);
    }
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignment operator called\n";
    if (this != &copy)
    {
        Animal::operator=(copy);         // Call base class assignment
        Brain *newBrain = new Brain(*copy.brain); // Create new brain
        delete brain;                    // Delete old brain first
        brain = newBrain;               // Assign new brain
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow >:)\n";
}

void Cat::getIdea(int i) const
{
    if (i >= 0 && i < 100)  // Use the parameter directly
    {
        std::cout << "Cat idea " << i << ": " << this->brain->printIdeas(i) 
                  << " at address " << this->brain->getIdeaAddress(i) << "\n";
    }
    else
    {
        std::cout << "Invalid idea index: " << i << "\n";
    }
}

void Cat::setIdea(int i, const std::string &idea)
{
    brain->addIdea(idea);
}