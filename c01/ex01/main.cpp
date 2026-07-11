/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 15:55:29 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/11 15:55:46 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 5;

	Zombie* horde = zombieHorde(N, "zeze");

	if (!horde)
		return 1;

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete[] horde;

	return 0;
}