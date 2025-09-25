/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialashqa <ialashqa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 20:42:49 by ialashqa          #+#    #+#             */
/*   Updated: 2025/09/23 20:42:49 by ialashqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    {
        std::cout << "\033[32m" << "=== TESTING CORRECT POLYMORPHISM (Animal/Dog/Cat) ===\n\n" << "\033[0m";
        
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        
        std::cout << "\nTypes:\n";
        std::cout << j->getType() << std::endl;
        std::cout << i->getType() << std::endl;
        
        std::cout << "\nSounds (virtual functions work correctly):\n";
        std::cout << "Cat sound: ";
        i->makeSound(); // will output the cat sound!
        std::cout << "Dog sound: ";
        j->makeSound(); // will output the dog sound!
        std::cout << "Animal sound: ";
        meta->makeSound(); // will output the animal sound!
        
        std::cout << "\n--- Cleanup ---\n";
        delete meta;
        delete j;
        delete i;
    }

    {
        std::cout << "\033[31m" << "\n=== WRONG CLASSES TEST (No Polymorphism) ===\n" << "\033[0m";
        
        const WrongAnimal* meta = new WrongAnimal();
        const WrongAnimal* i = new WrongCat();  // Note: WrongCat through WrongAnimal*
        
        std::cout << "\nTypes:\n";
        std::cout << "WrongCat type: " << i->getType() << std::endl;
        
        std::cout << "\nSounds (static binding - no virtual):\n";
        std::cout << "WrongCat through WrongAnimal*: ";
        i->makeSound(); // will output WrongAnimal sound, NOT WrongCat sound!
        std::cout << "WrongAnimal: ";
        meta->makeSound();
        
        std::cout << "\n--- Cleanup ---\n";
        delete meta;
        delete i;
    }
	
	return 0;
}
