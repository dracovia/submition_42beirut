/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:56:56 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/21 17:12:25 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
	: _x(0), _y(0)
{
}

Point::Point(const float x, const float y)
	: _x(x), _y(y)
{
}

Point::Point(const Point& other)
	: _x(other._x), _y(other._y)
{
}

Point& Point::operator=(const Point& other)
{
	(void)other;
	return (*this);
}

Point::~Point()
{
}

const Fixed& Point::getX(void) const
{
	return (_x);
}

const Fixed& Point::getY(void) const
{
	return (_y);
}