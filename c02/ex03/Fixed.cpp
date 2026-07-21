/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:52:55 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/21 17:12:16 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::_fractionalBits;

Fixed::Fixed()
	: _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
	: _fixedPointValue(value * (1 << _fractionalBits))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
	: _fixedPointValue(
		static_cast<int>(roundf(value * (1 << _fractionalBits)))
	)
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
	: _fixedPointValue(other._fixedPointValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		_fixedPointValue = other._fixedPointValue;

	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
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
	return (_fixedPointValue / (1 << _fractionalBits));
}

bool Fixed::operator>(const Fixed& other) const
{
	return (_fixedPointValue > other._fixedPointValue);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (_fixedPointValue < other._fixedPointValue);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (_fixedPointValue >= other._fixedPointValue);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (_fixedPointValue <= other._fixedPointValue);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (_fixedPointValue == other._fixedPointValue);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (_fixedPointValue != other._fixedPointValue);
}


Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;

	result.setRawBits(_fixedPointValue + other._fixedPointValue);
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;

	result.setRawBits(_fixedPointValue - other._fixedPointValue);
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	long	rawResult;

	rawResult = static_cast<long>(_fixedPointValue)
		* static_cast<long>(other._fixedPointValue);

	result.setRawBits(
		static_cast<int>(rawResult / (1L << _fractionalBits))
	);

	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	long	rawResult;

	rawResult = static_cast<long>(_fixedPointValue)
		* (1L << _fractionalBits);

	result.setRawBits(
		static_cast<int>(rawResult / other._fixedPointValue)
	);

	return (result);
}

Fixed& Fixed::operator++()
{
	++_fixedPointValue;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed oldValue(*this);

	++_fixedPointValue;
	return (oldValue);
}

Fixed& Fixed::operator--()
{
	--_fixedPointValue;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed oldValue(*this);

	--_fixedPointValue;
	return (oldValue);
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}