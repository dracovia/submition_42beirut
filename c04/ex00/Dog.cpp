/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:51:23 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/22 21:54:54 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    std::cout << "Dog constructor is called" << std::endl;
}
Dog::~Dog()
{
    std::cout << "Dog Destructor is called" << std::endl;
}
void Dog::makeSound()
{
        std::cout << "Dog is barking" << std::endl;
}