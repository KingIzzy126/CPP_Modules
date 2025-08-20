/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:31:10 by ialashqa          #+#    #+#             */
/*   Updated: 2025/08/18 14:24:28 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed {
    private:
        int                 fp; // Fixed-point value as an integer
        static const int    bits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &num);
        ~Fixed();
        Fixed &operator=(Fixed const &copy);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat(void) const;
        int toInt(void) const;
        // Bool Operators
        bool operator>(Fixed const &copy);
        bool operator>=(Fixed const &copy);
        bool operator<(Fixed const &copy);
        bool operator<=(Fixed const &copy);
        bool operator==(Fixed const &copy);
        bool operator!=(Fixed const &copy);
        // Arithmetic Operators
        float operator+(Fixed const &copy);
        float operator-(Fixed const &copy);
        float operator*(Fixed const &copy);
        float operator/(Fixed const &copy);
        // Increment and Decrement Operators
        Fixed operator++(void);
        Fixed operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
        // Min and Max
        static Fixed min(Fixed &first, Fixed &second);
        static Fixed max(Fixed &first, Fixed &second);
        static const Fixed min(Fixed const &first, Fixed const &second);
        static const Fixed max(Fixed const &first, Fixed const &second);
};

std::ostream &operator<<(std::ostream &out, Fixed const &fixed);

#endif