/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:46:29 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/19 16:46:29 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(std::string type);
        Cat(const Cat &copy);
        virtual ~Cat();
        Cat &operator=(const Cat &copy);

        virtual void makeSound() const;
};

#endif