/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 12:13:24 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/24 17:38:42 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"

#include <iostream>

int main()
{
    std::cout << "===== SUBJECT TEST =====" << std::endl;

    IMateriaSource* src = new MateriaSource();

    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;

    tmp = src->createMateria("ice");
    me->equip(tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;

    std::cout << std::endl;
    std::cout << "===== DEEP COPY TEST =====" << std::endl;

    MateriaSource source;
    source.learnMateria(new Ice());
    source.learnMateria(new Cure());

    Character original("original");

    original.equip(source.createMateria("ice"));
    original.equip(source.createMateria("cure"));

    Character copied(original);

    Character target("target");

    original.use(0, target);
    copied.use(1, target);

    std::cout << std::endl;
    std::cout << "===== ASSIGNMENT TEST =====" << std::endl;

    Character assigned("assigned");
    assigned = original;

    assigned.use(0, target);
    assigned.use(1, target);

    std::cout << std::endl;
    std::cout << "===== UNEQUIP TEST =====" << std::endl;

    AMateria* floorMateria = original.getMateria(0);

    original.unequip(0);
    original.use(0, target);

    delete floorMateria;

    std::cout << std::endl;
    std::cout << "===== INVALID OPERATIONS =====" << std::endl;

    original.use(-1, target);
    original.use(10, target);
    original.unequip(-1);
    original.unequip(10);
    original.equip(0);

    AMateria* unknown = source.createMateria("fire");

    if (unknown == 0)
        std::cout << "Unknown Materia type" << std::endl;

    delete unknown;

    return 0;
}