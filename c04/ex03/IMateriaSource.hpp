/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:32:25 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/24 15:38:06 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>

class AMateria;

class IMateriaSource
{
public:
    virtual ~IMateriaSource();

    virtual void learnMateria(AMateria* materia) = 0;
    virtual AMateria* createMateria(
        const std::string& type
    ) = 0;
};

#endif