/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:35:00 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/24 17:35:21 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        templates[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
        templates[i] = 0;

    copyTemplates(other);
}

MateriaSource& MateriaSource::operator=(
    const MateriaSource& other
)
{
    if (this != &other)
    {
        clearTemplates();
        copyTemplates(other);
    }

    return *this;
}

MateriaSource::~MateriaSource()
{
    clearTemplates();
}

void MateriaSource::clearTemplates()
{
    for (int i = 0; i < 4; i++)
    {
        delete templates[i];
        templates[i] = 0;
    }
}

void MateriaSource::copyTemplates(
    const MateriaSource& other
)
{
    for (int i = 0; i < 4; i++)
    {
        if (other.templates[i] != 0)
            templates[i] = other.templates[i]->clone();
        else
            templates[i] = 0;
    }
}

void MateriaSource::learnMateria(AMateria* materia)
{
    if (materia == 0)
        return;

    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == materia)
            return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (templates[i] == 0)
        {
            templates[i] = materia;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(
    const std::string& type
)
{
    for (int i = 0; i < 4; i++)
    {
        if (templates[i] != 0
            && templates[i]->getType() == type)
        {
            return templates[i]->clone();
        }
    }

    return 0;
}