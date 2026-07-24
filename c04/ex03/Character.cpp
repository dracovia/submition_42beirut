/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:05:42 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/24 15:28:54 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character() : name("")
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(const std::string& name) : name(name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;
}

Character::Character(const Character& other) : name(other.name)
{
    for (int i = 0; i < 4; i++)
        inventory[i] = 0;

    copyInventory(other);
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        clearInventory();
        name = other.name;
        copyInventory(other);
    }
    return *this;
}

Character::~Character()
{
    clearInventory();
}

void Character::clearInventory()
{
    for (int i = 0; i < 4; i++)
    {
        delete inventory[i];
        inventory[i] = 0;
    }
}

void Character::copyInventory(const Character& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.inventory[i] != 0)
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
}

const std::string& Character::getName() const
{
    return name;
}

void Character::equip(AMateria* materia)
{
    if (materia == 0)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == materia)
            return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == 0)
        {
            inventory[i] = materia;
            return;
        }
    }
}

void Character::unequip(int index)
{
    if (index < 0 || index >= 4)
        return;
    inventory[index] = 0;
}

void Character::use(int index, ICharacter& target)
{
    if (index < 0 || index >= 4)
        return;

    if (inventory[index] != 0)
        inventory[index]->use(target);
}

AMateria* Character::getMateria(int index)
{
    if (index < 0 || index >= 4)
        return 0;

    return inventory[index];
}
