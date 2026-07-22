/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 14:53:29 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/22 15:05:04 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("DefaultDiamond_clap_name"),
      ScavTrap(),
      FragTrap(),
      _name("DefaultDiamond")
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(30);

    std::cout << "DiamondTrap default constructor called for "
              << _name << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name"),
      ScavTrap(name),
      FragTrap(name),
      _name(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(30);

    std::cout << "DiamondTrap constructor called for "
              << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
    : ClapTrap(other),
      ScavTrap(other),
      FragTrap(other),
      _name(other._name)
{
    std::cout << "DiamondTrap copy constructor called for "
              << _name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy assignment operator called"
              << std::endl;

    if (this != &other)
    {
        ClapTrap::operator=(other);
        _name = other._name;
    }

    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called for "
              << _name << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: "
              << _name << std::endl;

    std::cout << "ClapTrap name: "
              << getName() << std::endl;
}