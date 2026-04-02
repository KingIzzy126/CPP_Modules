/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 16:14:05 by ismailalash       #+#    #+#             */
/*   Updated: 2026/04/02 16:45:39 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>
#include <string>

void printInt(int &x)
{
    std::cout << x << " ";
}

void incrementInt(int &x)
{
    x++;
}

void    ft_toupper(char &str)
{
    str = std::toupper(static_cast<unsigned char>(str));
}

int main (void)
{
    char str[] = {'a', 'b', 'c'};

    std::cout << "Before: " 
    << "\nstr[0]:" << str[0] 
    << "\nstr[1]:" << str[1] 
    << "\nstr[2]:" << str[2] << "\n";

    iter(str, 3, ft_toupper);

    std::cout << "After: "
    << "\nstr[0]:" << str[0]
    << "\nstr[1]:" << str[1]
    << "\nstr[2]:" << str[2] << "\n\n";

    // integer test
    std::cout << "Test array before decrement: ";
    int arr[] = {1, 2, 3, 4, 5};
    int i = 0;
    while (i < 5)
    {
        printInt(arr[i]);
        i++;
    }
    std::cout << "\n";
    
    std::cout << "Test array after increment: ";
    iter(arr, 5, incrementInt);
    i = 0;
    while (i < 5)
    {
        printInt(arr[i]);
        i++;
    }
    std::cout << "\n";

    return 0;
}