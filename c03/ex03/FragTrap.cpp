/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 12:42:28 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/22 13:19:06 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
    : ClapTrap("DefaultFragTrap")
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);

    std::cout << "FragTrap default constructor called for "
              << getName() << std::endl;
}

FragTrap::FragTrap(const std::string& name)
    : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);

    std::cout << "FragTrap constructor called for "
              << getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
    : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called for "
              << getName() << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "FragTrap copy assignment operator called"
              << std::endl;

    if (this != &other)
        ClapTrap::operator=(other);

    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called for "
              << getName() << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << getName()
              << " requests a positive high five!"
              << std::endl;
}