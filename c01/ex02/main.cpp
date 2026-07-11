/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/11 16:02:52 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/11 16:16:41 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Memory address of str:       " << &str << std::endl;
	std::cout << "Memory address held by PTR:  " << stringPTR << std::endl;
	std::cout << "Memory address held by REF:  " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value of str:                " << str << std::endl;
	std::cout << "Value pointed to by PTR:     " << *stringPTR << std::endl;
	std::cout << "Value pointed to by REF:     " << stringREF << std::endl;

	return 0;
}