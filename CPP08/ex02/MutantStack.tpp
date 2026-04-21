/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:04:02 by ialashqa          #+#    #+#             */
/*   Updated: 2026/04/21 19:37:07 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

//Comstructors, Destructor, and Assignment Operator

template <typename T>
MutanStack<T>::MutanStack()
{
}

template <typename T>
MutanStack<T>::MutanStack(const MutanStack &copy) : std::stack<T>(copy)
{
}

template <typename T>
MutanStack<T> &MutanStack<T>::operator=(const MutanStack &copy)
{
    if (this != &copy)
        std::stack<T>::operator=(copy);
    return *this;
}

template <typename T>
MutanStack<T>::~MutanStack()
{
}

// Forward Iterators
template <typename T>
typename MutanStack<T>::iterator MutantStack<T>::begin()
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutanStack<T>::iterator MutantStack<T>::end()
{
    return std::stack<T>::c.end();
}

// Const Iterators
template <typename T>
typename MutanStack<T>::const_iterator MutanStack<T>::begin() const
{
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutanStack<T>::const_iterator MutanStack<T>::end() const
{
    return std::stack<T>::c.end();
}

// Reverse Iterators
template <typename T>
typename MutanStack<T>::reverse_iterator MutanStack<T>::rbegin()
{
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutanStack<T>::reverse_iterator MutanStack<T>::rend()
{
    return std::stack<T>::c.rend();
}

// Const Reverse Iterators
template <typename T>
typename MutanStack<T>::const_reverse_iterator MutanStack<T>::rbegin() const
{
    return std::stack<T>::c.rbegin();
}

template <typename T>
typename MutanStack<T>::const_reverse_iterator MutanStack<T>::rend() const
{
    return std::stack<T>::c.rend();
}

#endif