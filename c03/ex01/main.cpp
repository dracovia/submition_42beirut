/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:48:10 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/22 12:18:25 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== ClapTrap ===" << std::endl;

    ClapTrap clap("CL4P-TP");

    clap.attack("target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    std::cout << "\n=== ScavTrap ===" << std::endl;

    ScavTrap scav("Serena");

    std::cout << "Name: " << scav.getName() << std::endl;
    std::cout << "Hit points: "
              << scav.getHitPoints() << std::endl;
    std::cout << "Energy points: "
              << scav.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: "
              << scav.getAttackDamage() << std::endl;

    scav.attack("enemy");
    scav.takeDamage(30);
    scav.beRepaired(10);
    scav.guardGate();

    std::cout << "\n=== Copy ===" << std::endl;

    ScavTrap copy(scav);
    copy.attack("another enemy");

    return 0;
}