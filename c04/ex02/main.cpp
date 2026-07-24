/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:34:54 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/24 12:10:19 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "===== ABSTRACT CLASS TEST =====" << std::endl;

    // Animal animal;
    // Animal* animal = new Animal();


    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << std::endl;

    std::cout << dog->getType() << ": ";
    dog->makeSound();

    std::cout << cat->getType() << ": ";
    cat->makeSound();

    std::cout << std::endl;
    std::cout << "===== DELETION TEST =====" << std::endl;

    delete dog;
    delete cat;

    std::cout << std::endl;
    std::cout << "===== ANIMAL ARRAY TEST =====" << std::endl;

    const int count = 4;
    Animal* animals[count];

    for (int i = 0; i < count; i++)
    {
        if (i < count / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << std::endl;

    for (int i = 0; i < count; i++)
    {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    std::cout << std::endl;
    std::cout << "===== ARRAY DESTRUCTION =====" << std::endl;

    for (int i = 0; i < count; i++)
        delete animals[i];

    std::cout << std::endl;
    std::cout << "===== DEEP COPY TEST =====" << std::endl;

    Dog original;
    original.setIdea(0, "Protect the house");

    Dog copy(original);
    copy.setIdea(0, "Sleep on the sofa");

    std::cout << "Original idea: "
              << original.getIdea(0) << std::endl;

    std::cout << "Copied idea:   "
              << copy.getIdea(0) << std::endl;

    return 0;
}