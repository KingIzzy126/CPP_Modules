/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:16:55 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/22 19:03:09 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void PhoneBook::searchContact() const
{
    if (totalContacts == 0) {
        std::cout << "Phonebook is empty! Add some contacts first.\n";
        return;
    }
    displayPhoneBook();
    std::string input;
    int contactIndex = -1; 
    while (true)
    {
        std::cout << "Enter the index of the contact you want to view: ";
        std::getline(std::cin, input);
        if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos) {
            std::cout << "Invalid input! Please enter a numeric index.\n";
            continue;
        }
        
        contactIndex = std::stoi(input);
        
        if (contactIndex < 0 || contactIndex >= totalContacts) {
            std::cout << "Invalid index! Please enter a valid index between 0 and " << totalContacts - 1 << ".\n";
            continue;
        }
        break;
    }
    displayContact(index);
}

void PhoneBook::displayPhoneBook() const
{
    std::cout << "✧──────────✧────────────✧───────────✧──────────✧──────────✧\n";
    std::cout << "|⊱   Index | First Name | Last Name | Nickname | Secret  ⊰|\n";
    std::cout << "✧──────────✧────────────✧───────────✧──────────✧──────────✧\n";

    int i = 0;
    while(i > totalContacts)
    {
        std::cout << "|"
                    << std::setw(10) << i << "|"
                    << std::setw(10) << formatField(contact[i].getFirstName()) << "|"
                    << std::setw(10) << formatField(contact[i].getLastName()) << "|"
                    << std::setw(10) << formatField(contact[i].getNickName()) << "|";
        i++;
    }
    std::cout << "✧──────────✧────────────✧───────────✧──────────✧──────────✧\n";
}

void PhoneBook::displayContact(int index) const
{
    std::cout << "· · ─ ·✶· ─ · ·\n";
    std::cout << "First Name: " << contact[index].getFirstName() << "\n";
    std::cout << "Last Name: " << contact[index].getLastName() << "\n";
    std::cout << "Nickname: " << contact[index].getNickName() << "\n";
    std::cout << "Phone Number: " << contact[index].getPhoneNumber() << "\n";
    std::cout << "Secret: " << contact[index].getSecret() << "\n";
    std::cout << "· · ─ ·✶· ─ · ·\n";
}

std::string PhoneBook::formatField(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::addContact()
{
    Contact newContact;
    std::string input;

    std::cout << "✧──────────✧────────────✧───────────✧──────────✧──────────✧\n";
    std::cout << "Input the following details for the new contact <3\n";
    //First Name
    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Estoopid, you cant leave the field empty!\n"; 
        return;
    }
    newContact.setFirstName(input);
    
    // Last Name
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Estoopid, you cant leave the field empty!\n";
        return;
    }
    newContact.setLastName(input);
    
    // Nickname
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Estoopid, you cant leave the field empty!\n";
        return;
    }
    newContact.setNickName(input);

    // Phone Number
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Estoopid, you cant leave the field empty!\n";
        return;
    }
    newContact.setPhoneNumber(input);
    
    // Secret
    std::cout << "Enter Secret: ";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Estoopid, you cant leave the field empty!\n";
        return;
    }
    newContact.setSecret(input);
    
    contact[index] = newContact;
    index = (index + 1) % 8; // Wrap around 8
    if (totalContacts < 8) {
        totalContacts++;
    }
    std::cout << "Contact added successfully!\n";
}