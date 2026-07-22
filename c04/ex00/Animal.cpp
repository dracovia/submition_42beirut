/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:42:17 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/22 21:59:10 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
        std::cout << "Animal default constructor is called" << std::endl;

}

Animal::Animal(const std::string& type):type(type)
{
    std::cout << "Animal constructor is called" << std::endl;
}
Animal::~Animal()
{
    std::cout << "Animal destructor is called" << std::endl;

}
void Animal::setType(const std::string& type)
{
    this->type = type;
}
const std::string& Animal::getType()
{
    return (type);
}
        
void Animal::makeSound()
{
        std::cout << "Animal is making a sound" << std::endl;
}