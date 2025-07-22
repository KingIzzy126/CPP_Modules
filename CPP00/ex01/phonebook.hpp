/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:16:52 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/22 20:13:56 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook {
    private:
        Contact contact[8];
        int index;
        int totalContacts;

        // Helper function to format fields
        std::string formatField(const std::string& field) const;
        bool isValidName(const std::string& str) const;
        bool isValidNickname(const std::string& str) const;
        bool isValidPhoneNumber(const std::string& str) const;
    public:
        PhoneBook(); // Constructor to initialize member variables
        void addContact();
        void searchContact() const;
        void displayPhoneBook() const;
        void displayContact(int index) const;
};

#endif