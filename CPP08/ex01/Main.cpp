/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:43:39 by ialashqa          #+#    #+#             */
/*   Updated: 2026/04/21 16:43:57 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    std::cout << "\nLarge Scale Test 10000 Numbers:\n";
    Span sp1(10000);
    for (int i = 0; i < 10000; i++)
        sp1.addNumber(i);
    
    std::cout << "Shortest Span: " << sp1.shortestSpan() << "\n";
    std::cout << "Longest Span: " << sp1.longestSpan() << "\n";
    
    std::cout << "\n----------------------------------------\n";
    
    Span test(20);
    
    test.addNumber(5);
    test.addNumber(15);
    test.addNumber(25);
    std::cout << "Added 3 single numbers: 5, 15, 25\n";
    
    // Method 1: Add a range of numbers
    int data[] = {10, 20, 30, 40, 50};
    test.addNumber(data, data + 5);
    std::cout << "Added 5 numbers from array: 10, 20, 30, 40, 50\n";
    
    // Method 2: Add numbers from a vector
    std::vector<int> vec;
    vec.push_back(60);
    vec.push_back(70);
    test.addNumber(vec.begin(), vec.end());
    std::cout << "Added 2 numbers from vector: 60, 70\n";
    
    std::cout << "Total numbers in Span: 10/20\n";
    std::cout << "Shortest Span: " << test.shortestSpan() << "\n";
    std::cout << "Longest Span: " << test.longestSpan() << "\n";

    //Add more to throw exception
    int more[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    try {
        std::cout << "Attempting to add 11 more numbers...\n";
        test.addNumber(more, more + 11);
    }
    catch (const Span::FullContainer& e) {
        std::cout  << e.what() << "\n";
    }
    return 0;
}