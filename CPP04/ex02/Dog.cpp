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

/* ---------------------------------------------- */
/*          Constructors & operators              */
/* ---------------------------------------------- */

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog default constructor called\n";
    brain = new Brain();
    if(!brain)
    {
        std::cout << "Failed to allocate memory for Brain\n";
        exit(1);
    }
}

Dog::Dog(std::string type) : Animal(type)
{
    std::cout << "Dog named constructor called\n";
    brain = new Brain();
    if(!brain)
    {
        std::cout << "Failed to allocate memory for Brain\n";
        exit(1);
    }
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called\n";
    brain = new Brain(*copy.brain); // Deep copy of Brain
    if(!brain)
    {
        std::cout << "Failed to allocate memory for Brain\n";
        exit(1);
    }
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignment operator called\n";
    if (this != &copy)
    {
        Animal::operator=(copy);         // Call base class assignment
        Brain *newBrain = new Brain(*copy.brain); // Create new brain
        delete brain;                    // Delete old brain first
        brain = newBrain;               // Assign new brain
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof\n";
}

void Dog::getIdea(int i) const
{
    if (i >= 0 && i < 100)
    {
        std::cout << "Dog idea " << i << ": " << this->brain->printIdeas(i) 
                  << " at address " << this->brain->getIdeaAddress(i) << "\n";
    }
    else
    {
        std::cout << "Invalid idea index: " << i << "\n";
    }
}

void Dog::setIdea(int i, const std::string &idea)
{
    brain->addIdea(idea);
}