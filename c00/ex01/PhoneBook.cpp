/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 11:47:03 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/08 20:54:01 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : _count(0), _nextIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

static std::string	formatCell(const std::string &text)
{
	if (text.length() > 10)
		return (text.substr(0, 9) + ".");
	return (text);
}

void	PhoneBook::addContact(const Contact &contact)
{
	_contacts[_nextIndex] = contact;
	_nextIndex = (_nextIndex + 1) % 8;
	if (_count < 8)
		_count++;
}

void	PhoneBook::displaySearchTable() const
{
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;

	for (int i = 0; i < _count; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatCell(_contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatCell(_contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatCell(_contacts[i].getNickname()) << std::endl;
	}
}

void	PhoneBook::displayContact(int index) const
{
	if (isValidIndex(index))
		_contacts[index].displayFullContact();
}

bool	PhoneBook::isValidIndex(int index) const
{
	return (index >= 0 && index < _count);
}

int	PhoneBook::getCount() const
{
	return (_count);
}