/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 12:26:44 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/16 18:48:55 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

const int Fixed::_fractionalBits;

/* ************************************************************************** */
/*                        ORTHODOX CANONICAL FORM                              */
/* ************************************************************************** */

Fixed::Fixed()
	: _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
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

/* ************************************************************************** */
/*                              CONSTRUCTORS                                    */
/* ************************************************************************** */

Fixed::Fixed(const int value)
	: _fixedPointValue(value << _fractionalBits)
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

/* ************************************************************************** */
/*                            RAW VALUE ACCESS                                  */
/* ************************************************************************** */

int Fixed::getRawBits(void) const
{
	return (_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	_fixedPointValue = raw;
}

/* ************************************************************************** */
/*                              CONVERSIONS                                     */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                         COMPARISON OPERATORS                                 */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                          ARITHMETIC OPERATORS                                */
/* ************************************************************************** */

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
	return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (Fixed(toFloat() / other.toFloat()));
}

/* ************************************************************************** */
/*                       INCREMENT / DECREMENT                                  */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                                MIN                                           */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                                MAX                                           */
/* ************************************************************************** */

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

/* ************************************************************************** */
/*                          INSERTION OPERATOR                                  */
/* ************************************************************************** */

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}