/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:09:54 by ismailalash       #+#    #+#             */
/*   Updated: 2026/04/09 16:36:44 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main (void)
{
    std::cout << "---Empty Array size test---\n";
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << "\n";

    //-----------------------------------------------------------------------//
    std::cout << "\n---Array of 5 integers test---\n";
    Array<int> arr(5);
    
    std::cout << "Array size: " << arr.size() << "\n";
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;
    
    std::cout << "Array contents: ";
    unsigned int i = 0;
    while (i < arr.size())
    {
        std::cout << arr[i] << " ";
        i++;
    }
    std::cout << "\n";
    //-----------------------------------------------------------------------//
    Array<int> copy = arr;
    copy[0] = 999;
    std::cout << "\nOriginal array after copy modification: " << arr[0] << "\n";
    
    try {
        arr[10] = 0;
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }
    return 0;
}