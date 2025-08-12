/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:57:11 by ialashqa          #+#    #+#             */
/*   Updated: 2025/08/12 19:32:05 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed(): integer(0) {
    std::cout << "Contructor called\n";
}

Fixed::Fixed(const Fixed &num)
{
    std::cout << "Copy constructor called\n";
    this->integer = num.integer;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed&copy) {
    std::cout << "Copy assignment operator called\n";
    this->integer = copy.getRawBits();
    return *this;
}