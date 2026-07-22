/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 21:48:11 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/22 21:51:09 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
    std::cout << "Cat constructor is called" << std::endl;
}
Cat::~Cat()
{
    std::cout << "Cat Destructor is called" << std::endl;
}
void Cat::makeSound()
{
        std::cout << "Cat is meowing" << std::endl;
}