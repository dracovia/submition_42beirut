/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:56:46 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/11 17:06:01 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
	: _name(name), _weapon(NULL)
{
}

void HumanB::setWeapon(Weapon& weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void)
{
	if (_weapon)
	{
		std::cout << _name << " attacks with their "
				  << _weapon->getType() << std::endl;
	}
	else
	{
		std::cout << _name << " has no weapon" << std::endl;
	}
}