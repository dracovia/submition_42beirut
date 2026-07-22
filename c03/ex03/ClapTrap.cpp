/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:48:40 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/22 12:14:46 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Default"),
      _hitPoints(10),
      _energyPoints(10),
      _attackDamage(0)
{
    std::cout << "ClapTrap default constructor called for "
              << _name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : _name(name),
      _hitPoints(10),
      _energyPoints(10),
      _attackDamage(0)
{
    std::cout << "ClapTrap constructor called for "
              << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name),
      _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints),
      _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap copy constructor called for "
              << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap copy assignment operator called"
              << std::endl;

    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }

    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called for "
              << _name << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name
                  << " cannot attack because it has no hit points!"
                  << std::endl;
        return;
    }

    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name
                  << " cannot attack because it has no energy points!"
                  << std::endl;
        return;
    }

    --_energyPoints;

    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!"
              << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;

    std::cout << "ClapTrap " << _name
              << " takes " << amount
              << " points of damage and now has "
              << _hitPoints << " hit points!"
              << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints == 0)
    {
        std::cout << "ClapTrap " << _name
                  << " cannot repair itself because it has no hit points!"
                  << std::endl;
        return;
    }

    if (_energyPoints == 0)
    {
        std::cout << "ClapTrap " << _name
                  << " cannot repair itself because it has no energy points!"
                  << std::endl;
        return;
    }

    --_energyPoints;
    _hitPoints += amount;

    std::cout << "ClapTrap " << _name
              << " repairs itself for " << amount
              << " hit points and now has "
              << _hitPoints << " hit points!"
              << std::endl;
}

const std::string& ClapTrap::getName() const
{
    return _name;
}

unsigned int ClapTrap::getHitPoints() const
{
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}

void ClapTrap::setName(const std::string& name)
{
    _name = name;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
    _hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
    _energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    _attackDamage = attackDamage;
}