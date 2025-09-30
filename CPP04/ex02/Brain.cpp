/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:17:57 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/25 20:17:57 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* ---------------------------------------------- */
/*          Constructors & operators              */
/* ---------------------------------------------- */

Brain::Brain(void) : index(0)
{
    std::cout << "Brain default constructor called\n";
}

Brain::Brain(const Brain &copy) : index(0)
{
    std::cout << "Brain copy constructor called\n";
    *this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
    if (this != &copy)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
        this->index = copy.index;
    }
    std::cout << "Brain assignment operator called\n";
    return *this;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called\n";
}

/* ---------------------------------------------- */
/*             Setters and Getters                */
/* ---------------------------------------------- */

void Brain::addIdea(const std::string &idea) // setter
{
    if (index < 100)
    {
        ideas[index] = idea;
        index++;
    }
    else
    {
        std::cout << "Brain is full, cannot add more ideas.\n";
    }
}

const std::string Brain::printIdeas(int const index) const // getter
{
    if (index >= 0 && index < 100 && ideas[index] != "")
        return "Idea " + ideas[index];
    else
        return "No idea at this index or index out of range.";
}

const std::string *Brain::getIdeaAddress(int const &index) const
{
    if (index >= 0 && index < 100)
        return &ideas[index];
    else
        return NULL;
}
