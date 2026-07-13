/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:29:24 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/13 15:19:04 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0]
				  << " <DEBUG|INFO|WARNING|ERROR>"
				  << std::endl;
		return 1;
	}

	Harl harl;

	harl.complain(argv[1]);

	return 0;
}