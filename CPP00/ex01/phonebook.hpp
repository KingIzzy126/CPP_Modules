/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:16:52 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/22 18:33:41 by ialashqa         ###   ########.fr       */
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
    public:
        void addContact();
        void searchContact() const;
        void displayPhoneBook() const;
        void displayContact(int index) const;
};

#endif