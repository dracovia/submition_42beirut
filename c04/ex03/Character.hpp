/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 13:20:28 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/24 13:20:41 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
private:
    std::string name;
    AMateria* inventory[4];

    void clearInventory();
    void copyInventory(const Character& other);

public:
    Character();
    Character(const std::string& name);
    Character(const Character& other);
    Character& operator=(const Character& other);
    virtual ~Character();

    virtual const std::string& getName() const;
    virtual void equip(AMateria* materia);
    virtual void unequip(int index);
    virtual void use(int index, ICharacter& target);

    AMateria* getMateria(int index);
};

#endif