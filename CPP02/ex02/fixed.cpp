/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:06:06 by ialashqa          #+#    #+#             */
/*   Updated: 2025/08/18 14:41:03 by ialashqa         ###   ########.fr       */
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

bool Fixed::operator>(Fixed const &copy)
{
    return (this->toFloat() > copy.toFloat());
}

bool Fixed::operator>=(Fixed const &copy)
{
    return (this->toFloat() >= copy.toFloat());
}

bool Fixed::operator<(Fixed const &copy)
{
    return (this->toFloat() < copy.toFloat());
}

bool Fixed::operator<=(Fixed const &copy)
{
    return (this->toFloat() <= copy.toFloat());
}

bool Fixed::operator==(Fixed const &copy)
{
    return (this->toFloat() == copy.toFloat());
}

bool Fixed::operator!=(Fixed const &copy)
{
    return (this->toFloat() != copy.toFloat());
}

float Fixed::operator+(Fixed const &copy)
{
    return (this->toFloat() + copy.toFloat());
}

float Fixed::operator-(Fixed const &copy)
{
    return (this->toFloat() - copy.toFloat());
}

float Fixed::operator*(Fixed const &copy)
{
    return (this->toFloat() * copy.toFloat());
}

float Fixed::operator/(Fixed const &copy)
{
    return (this->toFloat() / copy.toFloat());
}

Fixed Fixed::operator++(void)
{
    this->fp++;
    return (*this);
}

Fixed Fixed::operator--(void)
{
    this->fp++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    ++this->fp;
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    --this->fp;
    return (temp);
}

Fixed Fixed::min(Fixed &first, Fixed &second)
{
    if(first.toFloat() <= second.toFloat())
        return(first);
    else
        return(second);
}

Fixed Fixed::max(Fixed &first, Fixed &second)
{
    if(first.toFloat() >= second.toFloat())
        return(first);
    else
        return(second);
}

const Fixed Fixed::min(Fixed const &first, Fixed const &second)
{
    if(first.toFloat() <= second.toFloat())
        return(first);
    else
        return(second);
}

const Fixed Fixed::max(Fixed const &first, Fixed const &second)
{
    if(first.toFloat() >= second.toFloat())
        return(first);
    else
        return(second);
}