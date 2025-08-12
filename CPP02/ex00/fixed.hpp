/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:12:44 by ialashqa          #+#    #+#             */
/*   Updated: 2025/08/12 18:13:06 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Fixed {
    private:
        int                 integer;
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