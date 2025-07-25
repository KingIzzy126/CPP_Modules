/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 11:12:23 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/25 11:20:17 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *str_ptr = &str;
    std::string &str_ref = str;

    // Print values
    std::cout << "String variable: " << str << "\n";
    std::cout << "String pointer: " << *str_ptr << "\n";
    std::cout << "String reference: " << str_ref << "\n";

    // Print addresses
    std::cout << "Address of string variable: " << &str << "\n";
    std::cout << "Address of string pointer: " << str_ptr << "\n";
    std::cout << "Address of string reference: " << &str_ref << "\n";
    return 0;
}