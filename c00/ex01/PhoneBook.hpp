/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 20:19:23 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/08 20:19:31 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_count;
	int		_nextIndex;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact(const Contact &contact);
	void	displaySearchTable() const;
	void	displayContact(int index) const;
	bool	isValidIndex(int index) const;
	int		getCount() const;
};

#endif