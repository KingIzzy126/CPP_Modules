/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 20:15:54 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/25 20:15:54 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
        int index;
    public:
        Brain();
        Brain(const Brain &copy);
        Brain &operator=(const Brain &copy);
        ~Brain();

        void addIdea(const std::string &idea);
        void printIdeas() const;
};

#endif