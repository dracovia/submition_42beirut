/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:34:54 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/24 10:13:25 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "===== CORRECT POLYMORPHISM =====" << std::endl;

    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << std::endl;

    std::cout << "Type: " << dog->getType() << std::endl;
    std::cout << "Type: " << cat->getType() << std::endl;

    dog->makeSound();
    cat->makeSound();
    meta->makeSound();

    std::cout << std::endl;
    std::cout << "===== DESTRUCTION =====" << std::endl;

    delete cat;
    delete dog;
    delete meta;

    std::cout << std::endl;
    std::cout << "===== WRONG POLYMORPHISM =====" << std::endl;

    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << std::endl;

    std::cout << "Type: " << wrongMeta->getType() << std::endl;
    std::cout << "Type: " << wrongCat->getType() << std::endl;

    wrongMeta->makeSound();

    // Calls WrongAnimal::makeSound() because it is not virtual.
    wrongCat->makeSound();

    std::cout << std::endl;
    std::cout << "===== DIRECT WRONGCAT OBJECT =====" << std::endl;

    WrongCat directWrongCat;

    // Calls WrongCat::makeSound() because the static type is WrongCat.
    directWrongCat.makeSound();

    std::cout << std::endl;
    std::cout << "===== COPY TESTS =====" << std::endl;

    Dog originalDog;
    Dog copiedDog(originalDog);

    Cat originalCat;
    Cat assignedCat;
    assignedCat = originalCat;

    std::cout << "Copied dog type: "
              << copiedDog.getType() << std::endl;

    std::cout << "Assigned cat type: "
              << assignedCat.getType() << std::endl;

    std::cout << std::endl;
    std::cout << "===== FINAL DESTRUCTION =====" << std::endl;

    delete wrongCat;
    delete wrongMeta;

    return 0;
}