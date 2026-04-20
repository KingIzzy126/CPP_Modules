/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:38:47 by ialashqa          #+#    #+#             */
/*   Updated: 2026/04/20 15:54:49 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>

int main ()
{
    std::cout << "Vector contianer test:\n";
    {
        std::vector<int> numbers;
        numbers.push_back(1);
        numbers.push_back(4);
        numbers.push_back(2);
        numbers.push_back(6);
        numbers.push_back(7);

        try {
            std::vector<int>::iterator it = easyfind(numbers, 4);
            std::cout << "Element found: " << *it << "\n";
        }
        catch (const NotFound& e) {
            std::cout << e.what() << "\n";
        }
        try {
            easyfind(numbers, 10);
        }
        catch (const NotFound& e) {
            std::cout << e.what() << "\n";
        }
    }
    
    std::cout << "\nList Test:\n";
    {
        std::list<int> numbers;
        numbers.push_back(10);
        numbers.push_back(20);
        numbers.push_back(30);
        numbers.push_back(40);
        numbers.push_back(50);

        try {
            std::list<int>::iterator it = easyfind(numbers, 30);
            std::cout << "Element found: " << *it << "\n";
        }
        catch (const NotFound& e) {
            std::cout << e.what() << "\n";
        }
        try {
            easyfind(numbers, 60);
        }
        catch (const NotFound& e) {
            std::cout << e.what() << "\n";
        }
    }
    return 0;
}