/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:26:44 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/14 13:03:45 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
	: _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other; // calls assignment operator 
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other) // protects against self-assignment
		_fixedPointValue = other.getRawBits();

	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;

	_fixedPointValue = value << _fractionalBits; // shift left
}
Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;

	_fixedPointValue = roundf(value * (1 << _fractionalBits));
}

float Fixed::toFloat(void) const
{
	return (
		static_cast<float>(_fixedPointValue)
		/ static_cast<float>(1 << _fractionalBits)
	);
}
int Fixed::toInt(void) const
{
	return (_fixedPointValue >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}