/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 11:44:57 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/22 12:15:27 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
    : ClapTrap("DefaultScavTrap")
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);

    std::cout << "ScavTrap default constructor called for "
              << getName() << std::endl;
}

ScavTrap::ScavTrap(const std::string& name)
    : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);

    std::cout << "ScavTrap constructor called for "
              << getName() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
    : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called for "
              << getName() << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "ScavTrap copy assignment operator called"
              << std::endl;

    if (this != &other)
        ClapTrap::operator=(other);

    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for "
              << getName() << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (getHitPoints() == 0)
    {
        std::cout << "ScavTrap " << getName()
                  << " cannot attack because it has no hit points!"
                  << std::endl;
        return;
    }

    if (getEnergyPoints() == 0)
    {
        std::cout << "ScavTrap " << getName()
                  << " cannot attack because it has no energy points!"
                  << std::endl;
        return;
    }

    setEnergyPoints(getEnergyPoints() - 1);

    std::cout << "ScavTrap " << getName()
              << " attacks " << target
              << ", causing " << getAttackDamage()
              << " points of damage!"
              << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << getName()
              << " is now in Gate keeper mode."
              << std::endl;
}
    