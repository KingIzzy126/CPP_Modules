/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 19:18:44 by ismailalash       #+#    #+#             */
/*   Updated: 2026/04/08 14:58:20 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
    private:
        T*              _data;
        unsigned int    _size;
    
    public:
        // Constructors and destructor
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        ~Array();

        // Assignment operator
        Array &operator=(const Array &other);

        // Subscript operator
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;

        // Function
        unsigned int size() const;

        // Custom Exception
        class OutOfBoundsException : public std::exception
        {
        public:
            virtual const char* what(void) const throw();
        };
};

#include "Array.tpp"

#endif