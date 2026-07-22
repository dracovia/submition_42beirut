/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 10:48:10 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/22 11:23:10 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Basic actions ===" << std::endl;

    ClapTrap robot("CL4P-TP");

    robot.attack("a training dummy");
    robot.takeDamage(4);
    robot.beRepaired(2);

    std::cout << "\n=== No hit points test ===" << std::endl;

    robot.takeDamage(20);
    robot.attack("another robot");
    robot.beRepaired(5);

    std::cout << "\n=== Energy test ===" << std::endl;

    ClapTrap tiredRobot("LowBattery");

    for (int i = 0; i < 11; ++i)
        tiredRobot.attack("target");

    std::cout << "\n=== Copy test ===" << std::endl;

    ClapTrap original("Original");
    ClapTrap copy(original);

    ClapTrap assigned("Assigned");
    assigned = original;

    return 0;
}