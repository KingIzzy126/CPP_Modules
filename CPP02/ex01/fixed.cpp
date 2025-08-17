/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:44:56 by ismailalash       #+#    #+#             */
/*   Updated: 2025/08/13 18:59:36 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

Fixed::Fixed(): fp(0) {
    std::cout << "Default Contructor called\n";
}

Fixed::Fixed(const int value) {
    std::cout << "Int Constructor called!\n";
    this->fp = value << bits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float Constructor called!\n";
    this->fp = int(roundf(value * (1 << bits)));
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

int Fixed::toInt(void) const {
    return (int)(fp >> bits);
}

float Fixed::toFloat(void) const {
    return (float)(fp) / (float)(1 << bits);
}

std::ostream &operator<<(std::ostream &out, Fixed const &fixed) {
    out << fixed.toFloat();
    return out;
}