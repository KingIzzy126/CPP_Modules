/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:43:42 by ialashqa          #+#    #+#             */
/*   Updated: 2026/04/21 16:23:16 by ialashqa         ###   ########.fr       */
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
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() 
{
}


void Span::addNumber(int num)
{
    if (_numbers.size() >= _n) {
        throw FullContainer();
    }
    _numbers.push_back(num);
}

int Span::shortestSpan()
{
    if (_numbers.size() < 2) {
        throw NotEnoughNumbers();
    }
    
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    int shortest = tmp[1] - tmp[0];
    
    size_t i = 2;
    while (i < tmp.size()) {
        int span = tmp[i] - tmp[i - 1];
        if (span < shortest) {
            shortest = span;
        }
        i++;
    }
    return shortest;
}

int Span::longestSpan()
{
    if (_numbers.size() < 2) {
        throw NotEnoughNumbers();
    }
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());

    return (max - min);
}