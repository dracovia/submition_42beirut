/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:34:54 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/24 11:22:31 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== ANIMAL ARRAY TEST =====" << std::endl;

    const int animalCount = 6;
    Animal* animals[animalCount];

    for (int i = 0; i < animalCount; i++)
    {
        if (i < animalCount / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << std::endl;
    std::cout << "===== SOUND TEST =====" << std::endl;

    for (int i = 0; i < animalCount; i++)
    {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    std::cout << std::endl;
    std::cout << "===== DELETE THROUGH ANIMAL POINTERS ====="
              << std::endl;

    for (int i = 0; i < animalCount; i++)
        delete animals[i];

    std::cout << std::endl;
    std::cout << "===== DOG COPY CONSTRUCTOR TEST ====="
              << std::endl;

    Dog originalDog;
    originalDog.setIdea(0, "Protect the house");

    Dog copiedDog(originalDog);

    copiedDog.setIdea(0, "Sleep on the sofa");

    std::cout << "Original dog idea: "
              << originalDog.getIdea(0) << std::endl;

    std::cout << "Copied dog idea:   "
              << copiedDog.getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "===== CAT ASSIGNMENT TEST ====="
              << std::endl;

    Cat originalCat;
    originalCat.setIdea(0, "Catch the mouse");

    Cat assignedCat;
    assignedCat = originalCat;

    assignedCat.setIdea(0, "Ignore the mouse");

    std::cout << "Original cat idea: "
              << originalCat.getIdea(0) << std::endl;

    std::cout << "Assigned cat idea: "
              << assignedCat.getIdea(0) << std::endl;

    return 0;
}