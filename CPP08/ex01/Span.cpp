/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:43:42 by ialashqa          #+#    #+#             */
/*   Updated: 2026/04/20 18:57:40 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) 
{
}

Span::Span(unsigned int n) : _n(n) 
{
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span &Span::operator= (const Span &other)
{
    if (this != &other) {
        _n = other._n;
        _numbers = other._numbers;`
    }
    return *this;
}

Span::~Span() 
{
}

