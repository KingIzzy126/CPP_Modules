/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 16:40:57 by ismailalash       #+#    #+#             */
/*   Updated: 2026/03/31 20:04:47 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min(const T &a, const T &b)
{
    if (a < b)
        return a;
    else
        return b;
}

template<typename T>
T max(const T &a, const T &b)
{
    if (a > b)
        return a;
    else
        return b;   
}
#endif