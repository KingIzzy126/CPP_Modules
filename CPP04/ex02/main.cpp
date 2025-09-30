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
#include <iostream>

int main()
{
    // This should cause compilation error - uncomment to test
    // Animal* animal = new Animal(); // ❌ Cannot instantiate abstract class
    {
        std::cout << "\033[33m" << "Testing Abstract Animal (should work)\n"<< "\033[0m";
        
        // These should work - creating through derived classes
        Animal* dog = new Dog();
        Animal* cat = new Cat();
        
        std::cout << "Dog type: " << dog->getType() << std::endl;
        std::cout << "Cat type: " << cat->getType() << std::endl;
        
        dog->makeSound(); // Calls Dog::makeSound()
        cat->makeSound(); // Calls Cat::makeSound()
        
        delete dog;
        delete cat;
    }

    std::cout << std::endl;

    {
        std::cout << "\033[33m" << "Array test - 3 Dogs and 3 Cats\n"<< "\033[0m";
        Animal* animal_arr[6];

        // Create 3 Dogs using while loop
        int i = 0;
        while (i < 3)
        {
            std::cout << "Creating Dog " << (i + 1) << ":\n";
            animal_arr[i] = new Dog();
            i++;
        }

        // Create 3 Cats using while loop
        while (i < 6)
        {
            std::cout << "Creating Cat " << (i - 2) << ":\n";
            animal_arr[i] = new Cat();
            i++;
        }

        std::cout << std::endl;

        // Test polymorphism and add some ideas
        int dogNum = 1;
        int catNum = 1;
        int k = 0;
        while (k < 6)
        {
            if (Dog* d = dynamic_cast<Dog*>(animal_arr[k]))
            {
                std::cout << "Dog " << dogNum << " makes sound: ";
                animal_arr[k]->makeSound();
                d->setIdea(0, "Chase ball");
                d->setIdea(1, "Guard the house");
                d->setIdea(2, "Nap under the sun");
                dogNum++;
            }
            else if (Cat* c = dynamic_cast<Cat*>(animal_arr[k]))
            {
                std::cout << "Cat " << catNum << " makes sound: ";
                animal_arr[k]->makeSound();
                c->setIdea(0, "Climb curtain");
                c->setIdea(1, "Ignore human");
                c->setIdea(2, "Knock cup off table");
                catNum++;
            }
            k++;
        }

        std::cout << std::endl;

        // Print some ideas from each animal
         dogNum = 1;
        catNum = 1;
        k = 0;
        while (k < 6)
        {
            if (Dog* d = dynamic_cast<Dog*>(animal_arr[k]))
            {
                std::cout << "\n--- Dog " << dogNum << " Ideas ---\n";
                d->getIdea(0);
                d->getIdea(1);
                d->getIdea(2);
                dogNum++;
            }
            else if (Cat* c = dynamic_cast<Cat*>(animal_arr[k]))
            {
                std::cout << "\n--- Cat " << catNum << " Ideas ---\n";
                c->getIdea(0);
                c->getIdea(1);
                c->getIdea(2);
                catNum++;
            }
            k++;
        }

        std::cout << std::endl;

        // Delete all animals
        i = 0;
        while (i < 6)
        {
            delete animal_arr[i];
            i++;
        }
    }

    return 0;
}