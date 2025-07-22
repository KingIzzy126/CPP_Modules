/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:51:08 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/22 17:51:56 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;
    std::cout << "✧──────────✧────────────✧───────────✧──────────✧──────────✧\n"
            << "|⊱                  ＰＨＯＮＥＢＯＯＫ                   ⊰|\n"
            << "✧──────────✧────────────✧───────────✧──────────✧──────────✧\n"
            << "|             ✧ Welcome to the Phonebook! ✧               |\n"
            << "|⊱         Available commands: ADD, SEARCH, EXIT         ⊰|\n"
            << "|                                                         |\n";
    while(1)
    {
        std::cout << "|⊱ Enter command: ";
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            phonebook.addContact();
        }
        else if (command == "SEARCH")
        {
            phonebook.searchContact();
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting the Phonebook!\n";
            break;
        }
        else
        {
            std::cout << "Invalid command. Please try again.\n";
        }
    }
}
