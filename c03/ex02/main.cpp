/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:48:10 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/22 13:19:23 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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

    std::cout << "\n=== FragTrap ===" << std::endl;

    FragTrap frag("Fraggy");

    std::cout << "Name: " << frag.getName() << std::endl;
    std::cout << "Hit points: "
              << frag.getHitPoints() << std::endl;
    std::cout << "Energy points: "
              << frag.getEnergyPoints() << std::endl;
    std::cout << "Attack damage: "
              << frag.getAttackDamage() << std::endl;

    frag.attack("enemy robot");
    frag.takeDamage(40);
    frag.beRepaired(15);
    frag.highFivesGuys();

    std::cout << "\n=== FragTrap copy ===" << std::endl;

    FragTrap copy(frag);

    copy.attack("copy target");
    copy.highFivesGuys();

    std::cout << "\n=== FragTrap assignment ===" << std::endl;

    FragTrap assigned("Temporary");

    assigned = frag;
    assigned.attack("assignment target");
    assigned.highFivesGuys();

    std::cout << "\n=== Destruction order ===" << std::endl;

    return 0;
}