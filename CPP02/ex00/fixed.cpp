/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:57:11 by ialashqa          #+#    #+#             */
/*   Updated: 2025/08/13 18:13:09 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed(): fp(0) {
    std::cout << "Default Contructor called\n";
}

Fixed::Fixed(const Fixed &num)
{
    std::cout << "Copy constructor called\n";
    this->fp = num.fp;
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed&copy) {
    std::cout << "Copy assignment operator called\n";
    this->fp = copy.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called\n";
    return this->fp;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called\n";
    this->fp = raw;
}