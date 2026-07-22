/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:48:10 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/22 15:19:32 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main()
{
    std::cout << "=== DiamondTrap ===" << std::endl;

    DiamondTrap diamond("Shiny");

    std::cout << "Hit points: "
              << diamond.getHitPoints() << std::endl;

    std::cout << "Energy points: "
              << diamond.getEnergyPoints() << std::endl;

    std::cout << "Attack damage: "
              << diamond.getAttackDamage() << std::endl;

    diamond.whoAmI();
    diamond.attack("enemy");
    diamond.guardGate();
    diamond.highFivesGuys();

    std::cout << "\n=== Damage and repair ===" << std::endl;

    diamond.takeDamage(40);
    diamond.beRepaired(10);

    std::cout << "\n=== Copy constructor ===" << std::endl;

    DiamondTrap copy(diamond);

    copy.whoAmI();
    copy.attack("copy target");

    std::cout << "\n=== Assignment operator ===" << std::endl;

    DiamondTrap assigned("Temporary");

    assigned = diamond;
    assigned.whoAmI();
    assigned.attack("assignment target");

    std::cout << "\n=== Destruction order ===" << std::endl;

    return 0;
}