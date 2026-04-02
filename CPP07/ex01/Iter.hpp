/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 15:28:00 by ismailalash       #+#    #+#             */
/*   Updated: 2026/04/02 15:38:27 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T, typename F>
void  iter(T* array, const int length, F function)
{
    int i = 0;
    while (i < length)
    {
        function(array[i]);
        i++;
    }
}
#endif