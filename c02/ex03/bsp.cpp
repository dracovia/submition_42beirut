/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 15:58:16 by mfassad           #+#    #+#             */
/*   Updated: 2026/07/21 17:12:14 by mfassad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Positive → point is to the left of a → b
// Negative → point is to the right of a → b
// Zero     → a, b, and point are aligned

static Fixed crossProduct(
	const Point& a,
	const Point& b,
	const Point& point
)
{
	return (
		(b.getX() - a.getX()) * (point.getY() - a.getY())
		- (b.getY() - a.getY()) * (point.getX() - a.getX())
	);
}

bool bsp(
	Point const a,
	Point const b,
	Point const c,
	Point const point
)
{
	Fixed const sideAB = crossProduct(a, b, point);
	Fixed const sideBC = crossProduct(b, c, point);
	Fixed const sideCA = crossProduct(c, a, point);
	Fixed const zero(0);

	if (sideAB == zero || sideBC == zero || sideCA == zero)
		return (false);

	if (sideAB > zero && sideBC > zero && sideCA > zero)
		return (true);

	if (sideAB < zero && sideBC < zero && sideCA < zero)
		return (true);

	return (false);
}