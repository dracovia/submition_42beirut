/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 09:20:25 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/17 10:14:22 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

// char can be signed or unsigned i.e it can be negative so it should be casted to unsigned to avoid undefined behavior 
// toupper only acc unsigned char 
int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j]; j++)
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(argv[i][j])));
	}
	std::cout << std::endl;
	return (0);
}