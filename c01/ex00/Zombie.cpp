/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/09 21:13:47 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/09 21:24:07 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (const std::string  &name):_name(name)
{
    
}

const std::string &Zombie::getName(void) const
{
    return (_name);
}

void Zombie::announce( void )
{
    std::cout <<  getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}