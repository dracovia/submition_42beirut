/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 20:08:21 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/09 21:10:32 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact();
	~Contact();

	void	setContact(const std::string &firstName,
			const std::string &lastName,
			const std::string &nickname,
			const std::string &phoneNumber,
			const std::string &darkestSecret);

	const std::string	&getFirstName() const;
	const std::string	&getLastName() const;
	const std::string	&getNickname() const;

	void	displayFullContact() const;
};

#endif