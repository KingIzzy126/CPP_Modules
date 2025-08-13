/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:12:44 by ialashqa          #+#    #+#             */
/*   Updated: 2025/08/13 17:41:22 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Fixed {
    private:
        int                 fp; // Fixed-point value as an integer
        static const int    bits = 8;
    public:
        Fixed();
        Fixed(const Fixed &num);
        ~Fixed();
        Fixed &operator=(Fixed const &copy);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif