/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_Validation.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismailalashqar <ismailalashqar@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:15:44 by ismailalash       #+#    #+#             */
/*   Updated: 2025/07/22 20:15:50 by ismailalash      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

std::string PhoneBook::formatField(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

bool PhoneBook::isValidName(const std::string& str) const {
    size_t i = 0;
    while (i < str.length()) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            return false;
        }
        i++;
    }
    return true;
}

bool PhoneBook::isValidNickname(const std::string& str) const {
    size_t i = 0;
    while (i < str.length()) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))) {
            return false;
        }
        i++;
    }
    return true;
}

bool PhoneBook::isValidPhoneNumber(const std::string& str) const {
    size_t i = 0;
    while (i < str.length()) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return false;
        }
        i++;
    }
    return true;
}