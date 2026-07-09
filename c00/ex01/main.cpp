/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 20:51:15 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/09 21:18:48 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>

static bool	readNonEmptyField(const std::string &prompt, std::string &value)
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, value))
			return (false);
		if (!value.empty())
			return (true);
		std::cout << "Field cannot be empty." << std::endl;
	}
}

static bool	createContact(Contact &contact)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;

	if (!readNonEmptyField("First name: ", firstName))
		return (false);
	if (!readNonEmptyField("Last name: ", lastName))
		return (false);
	if (!readNonEmptyField("Nickname: ", nickname))
		return (false);
	if (!readNonEmptyField("Phone number: ", phoneNumber))
		return (false);
	if (!readNonEmptyField("Darkest secret: ", darkestSecret))
		return (false);
	contact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
	return (true);
}

static bool	parseIndex(const std::string &input, int &index)
{
	std::istringstream	stream(input);
	char				extra;

	if (!(stream >> index))
		return (false);
	if (stream >> extra)
		return (false);
	return (true);
}

static bool	searchContact(const PhoneBook &phoneBook)
{
	std::string	input;
	int			index;

	if (phoneBook.getCount() == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return (true);
	}
	phoneBook.displaySearchTable();
	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
		return (false);
	if (!parseIndex(input, index) || !phoneBook.isValidIndex(index))
	{
		std::cout << "Invalid index." << std::endl;
		return (true);
	}
	phoneBook.displayContact(index);
	return (true);
}

int	main(void)
{
	PhoneBook	phoneBook;
	Contact		contact;
	std::string	command;

	while (true)
	{
		std::cout << "phonebook> ";
		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
		{
			if (!createContact(contact))
				break ;
			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH")
		{
			if (!searchContact(phoneBook))
				break ;
		}
		else if (command == "EXIT")
			break ;
	}
	return (0);
}

