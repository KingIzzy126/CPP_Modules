/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:14:58 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/22 14:28:26 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void    Contact::setFirstName(std::string str)
{
    FirstName = str;
}

void    Contact::setLastName(std::string str)
{
    LastName = str;
}

void    Contact::setNickName(std::string str)
{
    NickName = str;
}

void    Contact::setPhoneNumber(std::string str)
{
    PhoneNumber = str;
}

void    Contact::setSecret(std::string str)
{
    Secret = str;
}


const std::string& Contact::getFirstName() const
{
    return (FirstName);
}

const std::string& Contact::getLastName() const
{
    return (LastName);
}

const std::string& Contact::getNickName() const
{
    return (NickName);
}

const std::string& Contact::getPhoneNumber() const
{
    return (PhoneNumber);
}

const std::string& Contact::getSecret() const
{
    return (Secret);
}
