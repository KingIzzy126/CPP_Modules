/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:43:42 by ialashqa          #+#    #+#             */
/*   Updated: 2026/04/20 17:10:25 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0) 
{
}

Span::Span(unsigned int n) : _n(n) 
{
}

Span::Span(const Span &copy) : _n(copy._n), _numbers(copy._numbers)
{
}