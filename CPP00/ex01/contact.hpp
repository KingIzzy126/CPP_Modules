/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 12:16:57 by ialashqa          #+#    #+#             */
/*   Updated: 2025/07/22 13:44:47 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string Secret;
    public:
        // Setters
        void                setFirstName(std::string str);
        void                setLastName(std::string str);
        void                setNickName(std::string str);
        void                setPhoneNumber(std::string str);
        void                setSecret(std::string str);
        // Getters
        const std::string&  getFirstName() const;
        const std::string&  getLastName() const;
        const std::string&  getNickName() const;
        const std::string&  getPhoneNumber() const;
        const std::string&  getSecret() const;
};

#endif