/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:04:02 by ialashqa          #+#    #+#             */
/*   Updated: 2026/05/01 16:04:47 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

//Comstructors, Destructor, and Assignment Operator

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy)
{
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy)
{
    if (this != &copy)
        std::stack<T>::operator=(copy);
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

// Forward Iterators
template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

// Const Iterators
template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return std::stack<T>::c.end();
}

// Reverse Iterators
template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return std::stack<T>::c.rend();
}

// Const Reverse Iterators
template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
    return std::stack<T>::c.rend();
}